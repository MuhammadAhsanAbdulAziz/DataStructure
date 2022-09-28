#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node *LC,*RC;
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
        Node* node = head;
        head = head->next;
        return node;
    }
};


void PreOrder(Node *node)
{
    if (node == nullptr)
        return;

    cout << node->data << " ";
    PreOrder(node->LC);
    PreOrder(node->RC);
}

void InOrder(Node *node)
{
    if (node == nullptr)
        return;

    InOrder(node->LC);
    cout << node->data << " ";
    InOrder(node->RC);
}

void PostOrder(Node *node)
{
    if (node == nullptr)
        return;

    PostOrder(node->LC);
    PostOrder(node->RC);
    cout << node->data << " ";
}




Node* creatnode(char data)
{
    Node* node = new Node;
    node->data = data;
    node->LC = node->RC = nullptr;
    return node;
}

int isOperate(char op)
    {
        if (op == '+' || op == '-')
            return 1;

        else if (op == '*' || op == '/')
            return 2;

        else if (op == '^')
            return 3;

        else if (op == '(')
            return 4;

        else
            return 0;
    }

void ExpressionTree(string postfix)
{
    STACK s;
    Node *root,*LC,*RC;

    for (int i = 0; i < postfix.length(); i++)
    {
        if(isOperate(postfix[i]) == 0)
        {
            root = creatnode(postfix[i]);
            s.push(root);
        }
        else
        {
            root = creatnode(postfix[i]);
            RC = s.pop();
            LC = s.pop();
            root->LC = LC;
            root->RC = RC;
            s.push(root);

        }
    }

    PreOrder(root);
    cout<< "\n";
    InOrder(root);
    cout<< "\n";
    PostOrder(root);


    
}

int main()
{
    string postFix = "ABC*+D/";

    ExpressionTree(postFix);


}

