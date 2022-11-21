#include <iostream>
#include <vector>
using namespace std;

void linearSearch(vector<int> arr, int num)
{
    int i = 0;
    int flag = 0;
    int count = 0;
    while (i < arr.size())
    {
        if (arr[i] != num)
        {
            i++;
            count++;
        }

        else
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Found at index " << count + 1;
    else
        cout << "Not Found";
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 3, 4, 10, 40};
    int num = 2;

    linearSearch(arr, num);
    return 0;
}
