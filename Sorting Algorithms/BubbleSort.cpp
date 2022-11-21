#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr)
{
    for (int i = arr.size(); i -->0;)
    {
        for (int j = 0; j < i ; j++)
        {
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
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

    bubbleSort(arr);

    return 0;
}
