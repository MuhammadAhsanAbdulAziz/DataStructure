#include <iostream>
#include <stack>

using namespace std;

class InfixToPostfix
{
private:
    stack<char> STACK;
    string postFix;

public:
    int isOperate(char op)
    {
        if (op == '+' || op == '-')
            return 1;

        else if (op == '*' || op == '/')
            return 2;

        else if (op == op == '^')
            return 3;

        else if (op == '(')
            return 4;

        else
            return 0;
    }

    void Conversion(string inFix)
    {
        for (int i = 0; i < inFix.length(); i++)
        {
            if (inFix[i] == ')')
            {
                while (STACK.top() != '(')
                {
                    postFix += STACK.top();
                    STACK.pop();
                }
                STACK.pop();
            }
            else
            {
                if (isOperate(inFix[i]) == 0)
                {
                    postFix += inFix[i];
                }
                else
                {
                    if (STACK.empty() || STACK.top() == '(')
                    {
                        STACK.push(inFix[i]);
                    }
                    else
                    {
                        while (!STACK.empty() && isOperate(inFix[i]) <= isOperate(STACK.top()))
                        {
                            postFix += STACK.top();
                            STACK.pop();
                        }
                        STACK.push(inFix[i]);
                    }
                }
            }
        }
        while (!STACK.empty())
        {
            postFix += STACK.top();
            STACK.pop();
        }

        cout << postFix;
    }
};

int main()
{
    string inFix = "a+b*(c/d)^2-x+y";

    InfixToPostfix conv;
    conv.Conversion(inFix);
}