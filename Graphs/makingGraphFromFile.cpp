#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// The coordinates file should follow a proper syntax


int main()
{
    ifstream inputFile("Coordinates.txt");

    string line;
    int rows, cols, x, y, val;
    int **arr;

    getline(inputFile, line);
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

    // if Graph is Weighted and Directed

    if (line == "w dg" || line == "W DG")
    {

        getline(inputFile, line); // skipping the second line containing the dimensions of array
        while (getline(inputFile, line))
        {
            istringstream ss(line);
            ss >> x >> y >> val;
            arr[x][y] = val;
        }
    }
    // if Graph is Weighed and Undirected

    else if (line == "w ug" || line == "W UG")
    {
        getline(inputFile, line); // skipping the second line containing the dimensions of array
        while (getline(inputFile, line))
        {
            istringstream ss(line);
            ss >> x >> y >> val;
            arr[x][y] = val;
            arr[y][x] = val;
        }
    }

    // if Graph is Unweighted and Directed

    else if (line == "uw dg" || line == "UW DG")
    {

        getline(inputFile, line); // skipping the second line containing the dimensions of array
        while (getline(inputFile, line))
        {
            istringstream ss(line);
            ss >> x >> y ;
            arr[x][y] = 1;
        }
    }

    // if Graph is Unweighted and Undirected

    else if (line == "uw ug" || line == "UW UG")
    {
        getline(inputFile, line); // skipping the second line containing the dimensions of array
        while (getline(inputFile, line))
        {
            istringstream ss(line);
            ss >> x >> y;
            arr[x][y] = 1;
            arr[y][x] = 1;
        }
    }

    cout << arr[0][4] << "\n";
    cout << arr[4][0];
}
