#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printlist(Node* node)
{
    while(node!=nullptr)
    {
        cout << node->data << endl;
        node = node->next;
    }
}


int main()
{
    Node* head = new Node;
    Node* first = new Node;
    Node* second = new Node;

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;
    
    second->data = 3;
    second->next = nullptr;


    printlist(head);
}
