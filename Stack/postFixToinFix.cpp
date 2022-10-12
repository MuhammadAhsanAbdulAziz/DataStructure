#include <iostream>
#include <stack>

using namespace std;

class InfixToPostfix
{
private:
    stack<string> STACK;
    string inFix;

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

    void Conversion(string postfix)
    {
        for (int i = 0; i < postfix.length(); i++)
        {
            if (isOperate(postfix[i]))
            {
                string firstOperand = STACK.top();
                STACK.pop();
                string secondOperand = STACK.top();
                STACK.pop();

                STACK.push("("+firstOperand + postfix[i] + secondOperand + ")");
            }
            else
            {
                string op(1,postfix[i]);
                STACK.push(op);
            }
        }
        
        cout << STACK.top();
    }
};

int main()
{
    string postfix = "AB+CD+*";

    InfixToPostfix conv;
    conv.Conversion(postfix);
}