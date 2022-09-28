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

void insertAtFront(Node** node,int data)
{
    Node* newNode = new Node;
    newNode->data = data; 
    newNode->next = *node;
    *node = newNode;

}

void insertAtEnd(Node** node,int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if(*node == nullptr)
    {
        *node = newNode;
    }
    else
    {
        Node *last  = *node;
        while(last->next !=nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}

void insertAfter(Node* previous,int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if(previous == nullptr)
    {
        previous = newNode;
    }
    else
    {
        Node* following = new Node;
        following = previous->next;

        previous->next = newNode;
        newNode->next = following;
    }
}

void countNodes(Node* head)
{
    int count = 0;
    while(head->next!=0)
    {
        count++;
        head = head->next;
    }
    cout << count;
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
    
    second->data = 4;
    second->next = nullptr;

    insertAtFront(&head,0);
    insertAfter(first,3);
    insertAtEnd(&head,5);
    
    printlist(head);

    countNodes(head);
}
