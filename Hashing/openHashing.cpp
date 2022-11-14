#include <iostream>
#include <vector>
using namespace std;

#define HS 10

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

struct Hnode
{
    int HI;
    Node *HT[HS];
    Hnode()
    {
        HI = 0;
        for (int i = 0; i < HS; i++)
        {
            HT[i] = nullptr;
        }
    }
    void insert(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            HI = arr[i] % HS;
            if (HT[HI] == nullptr)
            {
                HT[HI] = createNode(arr[i]);
            }
            else
            {
                Node *tempNode = HT[HI];
                while (tempNode->next != nullptr)
                {
                    tempNode = tempNode->next;
                }
                tempNode->next = createNode(arr[i]);
            }
        }
    }
    void search(int num)
    {
        HI = num % HS;
        if (HT[HI]->data == num)
        {
            cout << "Found at index " << HI;
        }
        else
        {
            Node *tempNode = HT[HI];
            while (tempNode->next->data != num)
            {
                tempNode = tempNode->next;
            }
            if (tempNode->next->data == num)
            {
                cout << "Found during the index of " << HI;
            }
            else
            {
                cout << "Number not Found ";
            }
        }
    }
};

int main()
{
    vector<int> arr = {5, 13, 2, 44, 100, 15, 33};
    Hnode h;
    h.insert(arr);
    h.search(100);

    return 0;
}
