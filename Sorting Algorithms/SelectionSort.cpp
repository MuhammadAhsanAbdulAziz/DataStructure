#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size() ; j++)
        {
            if(arr[i] > arr[j]) swap(arr[i],arr[j]);
        }
    }
    
    for(int x : arr)
    {
        cout << x << " ";
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {9, 3, 4, 2, 1, 8 };

    selectionSort(arr);

    
    return 0;
}
