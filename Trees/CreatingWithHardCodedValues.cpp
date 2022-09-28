#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *LC;
    Node *RC;
};

Node *CreateNode(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->LC = newnode->RC = nullptr;
    return newnode;
}

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

int main()
{
    // First Layer

    Node *root = CreateNode(1);

    // Second Layer

    root->LC = CreateNode(2);
    root->RC = CreateNode(3);

    // Third Layer

    root->LC->LC = CreateNode(4);
    root->LC->RC = CreateNode(5);
    root->RC->LC = CreateNode(6);
    root->RC->RC = CreateNode(7);

    // fourth Layer

    root->LC->RC->LC = CreateNode(9);
    root->RC->RC->LC = CreateNode(15);

    // Postfix To Infix Expression down below

    // struct Node *root = CreateNode('*');
    // root->LC = CreateNode('+');
    // root->RC = CreateNode('-');
    // root->LC->LC = CreateNode('a');
    // root->LC->RC = CreateNode('b');

    // root->RC->LC = CreateNode('c');
    // root->RC->RC = CreateNode('d');

    // cout << "InOrder : ";
    // InOrder(root);

    // cout << endl;
    // cout << "PreOrder : ";

    // PreOrder(root);

    // cout << endl;
    // cout << "PostOrder : ";

    // PostOrder(root);

}
