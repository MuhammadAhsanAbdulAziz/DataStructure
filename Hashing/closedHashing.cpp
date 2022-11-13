#include <iostream>
#include <vector>
using namespace std;

struct Hnode
{
    int HS, HI;
    float load_factor;
    int *HT;

    Hnode(int HS)
    {
        this->HS = HS;
        load_factor = 0;
        HI = 0;
        HT = new int[HS];
        for (int i = 0; i < HS; i++)
        {
            HT[i] = -1;
        }
    }
    void insert(vector<int> arr)
    {
        int elementsEntered = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            load_factor = float(elementsEntered) / float(HS);
            if (load_factor <= 0.5)
            {
                HI = arr[i] % HS;
                if (HT[HI] == -1)
                {
                    HT[HI] = arr[i];
                    elementsEntered++;
                }
                else
                {
                    int j = HI;
                    while (HT[j] != -1)
                    {
                        j = (j + 1) % HS;
                    }
                    HT[j] = arr[i];
                    elementsEntered++;
                }
            }
            else
            {
                HS = HS * 2;
                delete[] HT;
                HT = nullptr;
                int *newHT = new int[HS];
                for (int i = 0; i < HS; i++)
                {
                    newHT[i] = -1;
                }
                HT = newHT;
                i = -1;
                elementsEntered = 0;
            }
        }
    }
    void search(int num)
    {
        HI = num % HS;
        if (HT[HI] == num)
        {
            cout << "Found at index " << HI;
        }
        else
        {
            int j = HI;
            while (HT[j] != num)
            {
                j = (j + 1) % HS;
                if (j == HI)
                    break;
            }
            if (HT[j] == num)
            {
                cout << "Found at index " << j;
            }
            else
            {
                cout << "Number not Found ";
            }
        }
    }

    ~Hnode()
    {
        delete[] HT;
        HT = nullptr;
    }
};

int main()
{
    vector<int> arr = {5, 13, 2, 44, 100, 15, 33, 66, 88, 99, 4, 3, 1, 22, 55, 77, 101, 200, 300};
    Hnode h(10);
    h.insert(arr);
    h.search(33);

    return 0;
}
