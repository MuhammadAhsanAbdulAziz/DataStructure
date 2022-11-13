#include <iostream>
#include <vector>
using namespace std;

void binarySearch(vector<int> arr, int num)
{
    int low = 0;
    int high = arr.size()-1;
    int mid;
    int flag = 0;

    while(low <= high)
    {
        mid = (low + high) / 2 ;
        if(arr[mid] == num)
        {
            flag = 1;
            break;
        }
        else if(num < arr[mid]) high  = mid - 1;
        else if(num > arr[mid]) low  = mid + 1;
    }
    if (flag == 1)
        cout << "Found";
    else
        cout << "Not Found";
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 3, 4, 10, 40};
    int num = 3;

    binarySearch(arr, num);
    return 0;
}
