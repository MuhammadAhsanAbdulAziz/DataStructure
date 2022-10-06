#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createnode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;

    return node;
}

Node *insert(Node *head, int data)
{
    if (head == NULL)
    {
        head = createnode(data);
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = createnode(data);
    }
    return head;
}

void disp(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* shift(Node **head, int k)
{
    Node* HEAD = *head;
    if(k < 0)
    {
        k = k*(-1);
        for (int i = 0; i < k; i++)
        {
            Node* newnode = createnode(HEAD->data);
            HEAD = HEAD->next;
            Node* temp = HEAD;
            while(temp->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            Node* temp = HEAD;
            while(temp->next->next!=nullptr)
            {
                temp = temp->next;
            }
            Node* newnode = createnode(temp->next->data);
            temp->next = nullptr;
            newnode->next = HEAD;
            HEAD = newnode;
        }
    }
    return HEAD;

}

int main()
{
    Node *head = nullptr;
    head = insert(head, 0);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    head = shift(&head,2);

    disp(head);
}
