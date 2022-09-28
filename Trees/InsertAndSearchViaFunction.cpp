#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* LC;
    Node* RC;
};

Node *CreateNode(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->LC = newnode->RC = nullptr;
    return newnode;
}

Node* insert(Node* root,int data)
{
    if(root == nullptr)
    {
        root = CreateNode(data);
        return root;
    }
    else
    {
        Node* temp = root;
        while(temp!=nullptr)
        {
            if(data < temp->data)
            {
                if(temp->LC == nullptr)
                {
                    temp->LC = CreateNode(data);
                    return root;
                }
                else
                {
                    temp = temp->LC;
                }
            }
            else
            {
                if(temp->RC == nullptr)
                {
                    temp->RC = CreateNode(data);
                    return root;
                }
                else
                {
                    temp = temp->RC;
                }
            }
        }
    }
    return root;
  
}

void Search(Node* root, int data)

{
    int count = 1;
    while(root!=nullptr)
    {
        if(root->data != data)
        {
            if(data > root->data)
            {
                root = root->RC;
                count++;
            }
            else
            {
                root = root->LC;
                count++;
            }
        }
        else
        {
            break;
        }
    }
    if(root!=nullptr)
    {
        cout << "Found at level " << count ;
    }
    else
    {
        cout << "Not found";
    }
    
    
    
}

void InOrder(Node *node)
{
    if (node == nullptr)
        return;

    InOrder(node->LC);
    cout << node->data << " ";
    InOrder(node->RC);
}

int main()
{
    Node* tree = nullptr;

    tree = insert(tree,5);
    tree = insert(tree,2);
    tree = insert(tree,6);
    tree = insert(tree,3);

    InOrder(tree);

    cout <<'\n';
    
    Search(tree,3);
}