#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream inputFile("Coordinates.txt");

    string line;
    int rows, cols,x,y,val;
    int **arr;

    getline(inputFile,line);
    if (getline(inputFile, line))
    {
        istringstream ss(line);
        ss >> rows >> cols;
        arr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
        }
    }
    inputFile.clear();
    inputFile.seekg(0);
    getline(inputFile, line);

    
    if(line == "w" || line == "W")
    {
        getline(inputFile, line);
        getline(inputFile, line);
        while (getline(inputFile, line))
        {        
            istringstream ss(line);
            ss >> x >> y >> val;
            arr[x][y] = val;
        }
    }
    else
    {
        getline(inputFile, line);
        getline(inputFile, line);
        while (getline(inputFile, line))
        {        
            istringstream ss(line);
            ss >> x >> y ;
            arr[x][y] = 1;
        }
    }
    

    cout << arr[0][4];
}
