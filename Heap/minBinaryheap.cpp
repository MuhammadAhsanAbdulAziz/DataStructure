#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

// iterate through each nodes to heapify the heap tree to make it max heap tree

void minheapify(vector<int>& arr,int size , int i)
{
    int root = i;
    int LC = i*2 + 1 ; 
    int RC = (i*2) + 2;

    if(LC < size && arr[LC] < arr[root])
    {
        root = LC;
    }
    if(RC < size && arr[RC] < arr[root])
    {
        root = RC;
    }
    if(root != i)
    {
        swap(arr[root],arr[i]);
        minheapify(arr,size,root);
    }
}
// builds a min Heap Tree

void buildMinHeapTree(vector<int>& arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1 ; i >= 0; i--)
    {
        minheapify(arr,size,i);
    }
}
// sorts the already built Heap Tree

void heapSort(vector<int>& arr)
{
    buildMinHeapTree(arr);

    int size = arr.size();
    for (int i = size - 1; i >= 0 ; i--)
    {
        swap(arr[0],arr[i]);
        minheapify(arr,i,0);
    } 
}

void printArray(vector <int> arr)
{
    for(int x:arr)
    {
        cout << x << " ";
    }
}


int main()
{
    vector<int>arr = {19, 8, 2, 12, 20, 10, 18, 11, 14, 5};

    // buildMinHeapTree(arr);

    heapSort(arr);

    printArray(arr);   
}