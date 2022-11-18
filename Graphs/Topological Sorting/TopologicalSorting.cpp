#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// The coordinates file should follow a proper syntax like

// first line should contain " W UG or w ug "  for weighted and " UW UG or uw ug "  for unweighted
// second line conatins the dimensions for the 2d Array
// from 3rd line starts the coordinates along with weights if necessory

class graph
{
public:
    string line;
    vector<int> checked;
    int rows, cols, x, y, val;
    int **arr;

    void createGraph()
    {
        fstream inputFile("Coordinates.txt");

        getline(inputFile, line); // skipping the first line to initialize the array with second line's dimensions.
        if (getline(inputFile, line))
        {
            istringstream ss(line);
            ss >> rows >> cols;
            arr = new int *[rows];
            for (int i = 0; i < rows; i++)
            {
                arr[i] = new int[cols];
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    arr[i][j] = 0;
                }
            }
        }
        inputFile.clear();        // clearing the file to reuse if from beginning
        inputFile.seekg(0);       // pointing the pointer to the start of the file
        getline(inputFile, line); // getting the first line which consist of the nature of the graph

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
                ss >> x >> y;
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
    }

    int findInDegree()
    {
        vector<int> iN(rows);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arr[i][j] != 0)
                {
                    iN[j]++;
                }
            }
        }
        if (!checked.empty())
            {
                for (int i = 0; i < checked.size(); i++)
                {
                    iN[checked[i]] = -1;
                }
            }
        int flag = 0;
        int Vertice;
        for (int k = rows-1; k >=0; k--)
        {
            if (iN[k] == 0)
            {
                Vertice = k;
                checked.push_back(Vertice);
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            return Vertice;
        else
            return -1;
    }

    string topologicalSorting()
    {
        string sorted;
        int v;

        for (int count = 0; count < rows; count++)
        {
            v = findInDegree();
            if (v == -1)
            {
                return "Graph has a cycle";
            }
            sorted.append(to_string(v) + " ");
            for (int i = 0; i < rows; i++)
            {
                arr[v][i] = 0;
            }
        }

        return sorted;
    }
};

int main()
{
    graph g;
    g.createGraph();

    cout << g.topologicalSorting();
}
