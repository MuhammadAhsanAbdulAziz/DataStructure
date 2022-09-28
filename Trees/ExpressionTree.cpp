#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    char data;
    Node* LC;
    Node* RC;
    Node* next = nullptr;
};
struct STACK
{
    Node* head;

    void push(Node* node)
{
    

    if(head == nullptr)
    {
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}
Node* pop()
{
    Node* p = head;
    head = head->next;
    return p;

}

};



Node* createnode(char data)
{
    Node* node = new Node;
    node->data = data;
    node->LC = node->RC = nullptr;
    return node;
}


void InOrder(Node *node)
{
    if (node == nullptr)
        return;

    InOrder(node->LC);
    cout << node->data << " ";
    InOrder(node->RC);
}



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



void ExpressionTree(string postFix)
{
    STACK s;
    Node* root,*RC,*LC;

    for (int i = 0; i < postFix.length(); i++)
    {
        if(isOperate(postFix[i]) == 0)
        {
            root = createnode(postFix[i]);
            s.push(root);
        }
        else
        {
            root = createnode(postFix[i]);
            RC = s.pop();
            LC = s.pop();
            root->LC = LC;
            root->RC = RC;
            s.push(root);
        }
    }


    InOrder(root);

    
}

int main()
{
    string postFix = "ABC*+D/";

    ExpressionTree(postFix);


}
