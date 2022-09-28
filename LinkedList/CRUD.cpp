#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}

Node *insert(Node *head, int data)
{
    if (head == nullptr)
    {
        head = createNode(data);
        return head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = createNode(data);
        return head;
    }
}

Node* insert(Node* head,vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {    
        if(head == nullptr)
        {
            head = createNode(data[i]);

        }
        else
        {
            Node* temp = head;
            while(temp->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->next = createNode(data[i]);
        }
        
    }
    return head;
}

void printlist(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

Node *Delete(Node *head, string direction)
{
    Node *temp = head;
    if (direction == "front")
    {
        if (head == nullptr)
            return NULL;

        head = head->next;
        delete temp;
        temp = nullptr;
    }
    else if (direction == "end")
    {
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    return head;
}

void countNodes(Node *head)
{
    int count = 1;
    while (head->next != nullptr)
    {
        count++;
        head = head->next;
    }
    cout << "Total nodes are : " << count;
}

int main()
{
    Node *head = nullptr;

    // head = insert(head, 1);
    // head = insert(head, 2);
    // head = insert(head, 3);
    // head = insert(head, 4);

    // head = Delete(head, "front");

    vector<int> data = {1,2,3,4,5,6,7,8};

    head = insert(head,data);

    printlist(head);

    countNodes(head);
}
