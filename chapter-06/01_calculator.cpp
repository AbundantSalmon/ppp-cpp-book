// Implementation of the calculator as described in chapter 6

#include "../std_lib_facilities.h"

class Token
{
public:
    char kind;
    double value;
};

class Token_stream
{
public:
    void putback(Token t); // get a Token
    Token get();           // put a Token back

private:
    bool full{false}; // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

void Token_stream::putback(Token t)
{
    if (full)
    {
        error("putback() into a full buffer");
    }
    buffer = t;  // copy t to buffer
    full = true; // buffer is now full
}

Token Token_stream::get()
{
    if (full) // do we already have a Token ready?
    {
        full = false; // remove Token from buffer
        return buffer;
    }

    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
    case ';': // for “print”
    case 'q': // for "quit"
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
        return Token{ch}; // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{'8', val};
    }
    default:
        error("Bad token");
    }
}

Token_stream ts;
// forward decalration of function due to circular logic of
// primary(), term(), and expression() functions
double expression();

// deal with numbers and brackets
double primary()
{
    Token t = ts.get(); // get the next Token from the Token stream
    switch (t.kind)
    {
    case '(': // handle '(' express ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
        {
            error("')' expected");
        }
        return d;
    }
    case '8':           // we use '8' to represent a number
        return t.value; // return the number's value
    default:
        error("primary expected");
    }
}

// deal with * and /
double term()
{
    double left = primary();
    Token t = ts.get(); // get the next Token from the Token stream

    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
            {
                error("divide by zero");
            }
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t); // put t back into the Token stream
            return left;
        }
    }
}

// deal with + and -
double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = ts.get();   // get the next Token from the Token stream

    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term(); // evaluate term and add
            t = ts.get();
            break;
        case '-':
            left += term(); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t); // put t back into the token stream
            return left;
        }
    }
}

// main loop and deals with errors
int main()
{
    try
    {
        double val = 0;
        while (cin)
        {
            Token t = ts.get();
            if (t.kind == 'q')
                break;         // ‘q’ for “quit”
            if (t.kind == ';') // ‘;’ for “print now”
                cout << "=" << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
        keep_window_open();
        return 0;
    }
    catch (exception &e)
    {
        cerr << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "exception \n";
        keep_window_open();
        return 2;
    }
}