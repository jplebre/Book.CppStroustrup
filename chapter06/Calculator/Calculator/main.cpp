//
//  main.cpp
//  calculator_chapter6
//
//  Created by João Pedro Lebre on 02/05/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

const char number = '8'; //for use in switch statements
const char quit = 'q'; //for use in "quit" input
const char printResult = ';'; // for use to print result
const string prompt = ">";
const string result = "=";

const char name = 'a'; //"name" token - to be used naming variables
const char let = 'L'; //"let" kind token - to be used to call declaration of variables
const string declarationLetKey = "let";


//---------------------------------------------------------------------

class Token
{
public:
    char kind;
    int value;
    string name;
    
    //constructors for Token
    Token(char ch):kind(ch), value(0) {}
    Token(char ch, int val):kind(ch), value(val) {}
    Token(char ch, string n):kind(ch), name(n) {}
};


class Token_Stream
{
public:
    Token_Stream(); //makes a Token_Stream
    Token get(); //get a token from the stream
    void putback(Token t); //put a token back in the stream
    void ignoreCharacter(char c); //ignore illegal characters to our program
    
private:
    //other implementation details
    bool full; //is there a token in the buffer??
    Token buffer; //store Tokens here, in case putback needs a place to putback
};

//constructor for Token_Stream, which initializes the new Token_stream with a not false "full", and buffer of 0
Token_Stream::Token_Stream()
:full(false), buffer(0){ }


//defining member function of token_stream
void Token_Stream::putback(Token t)
{
    if (full) error("attempted putback() into a full buffer"); //is it already full?
    
    buffer = t; //copy t into buffer
    full = true; //set buffer to full
}

//defining member function of token_stream get()
Token Token_Stream::get()
{
    //check if there is a token to get
    if(full)
    {
        full = false; //delete buffer so other values can be put there
        return buffer; //get the value
    }
    
    //now we decide what to do with the value we just got
    char ch;
    cin >> ch;
    
    switch(ch)
    {
    case printResult: //used for "return value"
    case quit: //used for user to quit
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case'/':
        return Token (ch); //all these values need to be passed as themselves for the other methods
    case'.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch); //put digit back into input stream
            double val;
            cin >> val; //read the numbers or the . (for floating point numbers)
            return Token(number, val); //put those numbers into a token of kind '8', value from cin (float numbers eg 1.2)
        }
    default:
            if(isalpha(ch))
            {
                cin.putback(ch);
                string s;
                cin>>s;
                
                //while there are inputs in get(), and as long as those inputs are alpha or digits
                //concatonate the new character to our string
                //this ensure variables are "legal"
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
                if (s== declarationLetKey) return Token(let);
                return Token(name,s);
            }
        error("Bad Token");
    }
}

void Token_Stream::ignoreCharacter(char c)
//to be used by clean_up_mess()
//looks to c if a token of kind "c" is on the buffer. If so, deletes the buffer
//also looks "ahead" and checks if the next value is also of kind c. If so, ignores the cin until cin is not of kind c
{
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    
    full = false;
    
    char ch = 0;
    while (cin>> ch)
        if (ch == c) return;
}



Token_Stream tokenStream; //instantiates a Token_Stream called tokenStream
double expression(); //declares expression - which primary() needs to use


//---------------------------------------------------------------------


class Variables
{
public:
    string name;
    double value;
    Variables (string n, double v): name(n), value(v) {}
};

vector<Variables>variablesTable;

bool is_declared(string var)
//checks if var is already on the table
{
    for (int i = 0; i<variablesTable.size(); ++i)
        if (variablesTable[i].name == var) return true;
    return false;
}

double define_name(string var, double val)
//adds variable name var, value val to the table
{
    //if variable already on the table (if is_declared() returns true)
    if(is_declared(var)) error(var, " declared twice");
    
    variablesTable.push_back(Variables(var, val));
    return val;
}

double declaration()
// assume user input let (as checked by statement()
// check the input follows the format name = expression
//declare a variable to be added to variablesTable with that name and value "expression"
{
    Token t = tokenStream.get();
    if (t.kind != name) error("name expected in variable declaration");
    string var_name = t.name;
    
    Token t2 = tokenStream.get();
    if (t2.kind != '=') error("missing an = in the variable declaration of ", var_name);
    
    double d = expression();
    define_name(var_name,d);
    return d;
}


//---------------------------------------------------------------------

double statement()
{
    Token t = tokenStream.get();
    switch (t.kind)
    {
        case let:
            return declaration();
        default:
            tokenStream.putback(t);
            return expression();
    }
}



double primary()
{
    Token t = tokenStream.get();
    switch (t.kind)
    {
        case '(':
        {
            double d = expression();
            t = tokenStream.get();
            if (t.kind != ')' ) error("')' expected");
            return d;
        }
        case number:
            return t.value;
        case '+':
            return primary();
        case '-':
            return - primary();
        default:
            error("primary expected");
    }
    
}

double term()
{
    double left = primary();
    Token t = tokenStream.get();
    
    while (true)
    {
        switch(t.kind)
        {
            case'*':
                left *= primary();
                t = tokenStream.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) error("division by 0 not allowed");
                left /= d;
                t = tokenStream.get();
                break;
            }
            case '%':
            {
                double d = primary();
                int i1 = int(left);
                int i2 = int(d);
                
                //check if values are integers. If not, modulo can't run
                if (i1 != left) error("left hand operand of % not an integer");
                if (i2 != d) error("right hand operand of % not an integer");
                if (i2 == 0) error("%: modulo cannot divide by 0");
                
                left = i1%i2;
                t = tokenStream.get();
                break;
            }
            default:
                tokenStream.putback(t);
                return left;
        }
    }
}

double expression()
{
    double left = term();
    Token t = tokenStream.get();
    //cout << "I'm inside expression!";
    
    while(true)
    {
        switch (t.kind)
        {
            case '+':
                left += term();
                t = tokenStream.get();
                break;
            case '-':
                left -= term();
                t = tokenStream.get();
                break;
            default:
                tokenStream.putback(t);
                return left;
        }
        
    }
}

void clean_up_mess()
{
    tokenStream.ignoreCharacter(printResult);
}


void calculate()
{
    //while there is input, check if it's an exit command (q), an execute command (;) or values for our token
    while (cin)
    try{
        cout << prompt; //prompt to user
        
        Token t = tokenStream.get();
        
        while (t.kind == printResult) t = tokenStream.get();
        if (t.kind == quit) return;
        
        tokenStream.putback(t);
        cout << result << statement() << endl;
        
    }
    
    catch(exception& e)
    {
        cerr<< e.what() << endl;
        clean_up_mess();
    }
}




vector<Token>tokens;


double get_value(string s)
//returns the value of the variable named s
{
    for (int i=0; i<variablesTable.size(); ++i)
        if (variablesTable[i].name == s) return variablesTable[i].value;
    error("get: undefined variable ", s);
}

void set_value(string s, double d)
//looks for the name s, sets value to d
{
    for (int i=0; i<variablesTable.size(); ++i)
        if(variablesTable[i].name == s)
        {
            variablesTable[i].value = d;
            return;
        }
    error("set:undefined variable ", s);
}

int main()
try
{
    //defining some variables:
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);
    
    calculate();
    
    keep_window_open(); //for windows consoles
    return 0;
}
        
catch(exception& e)
    {
        cerr<< e.what() << endl;
        keep_window_open("~");
        
        /* the above line is the same as:
        cout << "Please enter ~ to close the program";
        char ch;
        while (cin>>ch)
            if (ch == '~') return 1;
        */
        
        return 1;
    }
        
catch(...)
    {
        cerr << "exception \n";
        keep_window_open("~");
        return 2;
    }

