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

Node* Delete(Node* root,int data)
{
    if(root == nullptr) return root;
    else if(data < root->data) root->LC = Delete(root->LC,data);
    else if(data > root->data) root->RC = Delete(root->RC,data);
    else{
     if(root->LC == nullptr && root->RC == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if(root->LC == nullptr)
        {
            Node* temp = root;
            root = root->RC;
            delete temp;
        }
        else if(root->RC == nullptr)
        {
            Node* temp = root;
            root = root->LC;
            delete temp;
        }
        else {
			Node *temp = new Node;
            while(root->RC->LC !=nullptr)
            {
                root->RC = root->RC->LC; 
            }
            temp = root->RC;
			root->data = temp->data;
			root->RC = Delete(root->RC,temp->data);
		}
    }
    return root;
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

    // Inserting nodes in Binary search Tree

    tree = insert(tree,8);
    tree = insert(tree,3);
    tree = insert(tree,10);
    tree = insert(tree,1);
    tree = insert(tree,6);

    // Deleting the node containing 3

    tree = Delete(tree,3);
    
    // searching 3

    Search(tree,3);
    
    InOrder(tree);
}