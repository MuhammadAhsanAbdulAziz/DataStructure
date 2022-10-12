#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

// iterate through each nodes to heapify the heap tree to make it max heap tree
void maxheapify(vector<int>& arr,int size , int i)
{
    int root = i;
    int LC = i*2 + 1 ; 

    if(LC < size && arr[LC] > arr[root])
    {
        root = LC;
    }
    if(RC < size && arr[RC] > arr[root])
    {
        root = RC;
    }
    if(root != i)
    {
        swap(arr[root],arr[i]);
        maxheapify(arr,size,root);
    }
}
// builds a max Heap Tree
void buildMaxHeapTree(vector<int>& arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1 ; i >= 0; i--)
    {
        maxheapify(arr,size,i);
    }
}

// sorts the already built Heap Tree
void heapSort(vector<int>& arr)
{
    buildMaxHeapTree(arr);

    int size = arr.size();
    for (int i = size - 1; i >= 0 ; i--)
    {
        swap(arr[0],arr[i]);
        maxheapify(arr,i,0);
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
    vector<int>arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    heapSort(arr);

    printArray(arr);   

}
