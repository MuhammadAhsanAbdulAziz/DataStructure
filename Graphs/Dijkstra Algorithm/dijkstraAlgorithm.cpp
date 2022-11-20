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
    int rows, x, y, val;
    int **arr;
    int **path;

    void createGraph()
    {
        fstream inputFile("Coordinates.txt");

        getline(inputFile, line); // skipping the first line to initialize the array with second line's dimensions.
        if (getline(inputFile, line))
        {
            istringstream ss(line);
            ss >> rows;
            arr = new int *[rows];
            for (int i = 0; i < rows; i++)
            {
                arr[i] = new int[rows];
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < rows; j++)
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

    int SmallestUnknownVertex(int dist[], bool UnknownKnownVertices[])
    {
        int min_vertex;
        int min = INT_MAX;
        for (int i = 0; i < rows; i++)
        {
            if (dist[i] <= min && UnknownKnownVertices[i] == false)
            {
                min_vertex = i;
                min = dist[i];
            }
        }
        return min_vertex;
    }

    void printGraph(int dist[], int src)
    {
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << i << " \t\t\t\t" << dist[i] << endl;
        }

        cout << endl
             << endl
             << "Directions :" << endl
             << endl;

        for (int i = 0; i < rows; i++)
        {
            cout << src;
            for (int j = 0; j < rows; j++)
            {
                if (path[i][j] > -1)
                {
                    cout << "-->";
                    cout << path[i][j] << "-->" << i;
                }
            }
            cout << endl;
        }
    }

    void dijkstra(int src)
    {
        int *dist;
        bool *UnknownKnownVertices;
        int count = 0;

        // creating 1d Array for distance and UnUnknownKnownVertices
        // initializing
        for (int i = 0; i < rows; i++)
        {
            dist = new int[i];
            UnknownKnownVertices = new bool[i];
        }

        // creating 2d Array "path" for Path directions
        path = new int *[rows];

        // Declaraing
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                path[i] = new int[rows];
            }
        }

        // Initializing 2d Array "path" cells with "-1"
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                path[i][j] = -1;
            }
        }

        // Initializing 2d Array "dist" and "UnknownKnownVertices" cells with "Maximum Integer number" and "false"
        for (int i = 0; i < rows; i++)
        {
            dist[i] = INT_MAX;
            UnknownKnownVertices[i] = false;
        }

        // Initialzing the src in the distance array to "0"
        dist[src] = 0;

        for (int i = 0; i < rows; i++)
        {
            int v = SmallestUnknownVertex(dist, UnknownKnownVertices); // finding the smallest unknown Vertex
            if (v == -1) // if vertex is invalid
            {
                break;
            }
            else
            {
                UnknownKnownVertices[v] = true; // making the found vertex true so it wont be choose in future
                for (int j = 0; j < rows; j++)
                {
                    if (arr[v][j] > 0 && UnknownKnownVertices[j] != true && dist[v] + arr[v][j] < dist[j])
                    {

                        dist[j] = dist[v] + arr[v][j]; // updating the dist array 
                        path[j][count] = v; // updating the path 2d Array to track down the vertices
                        count++;
                    }
                }
            }
        }

        printGraph(dist, src);
    }
};

int main()
{
    graph g;
    g.createGraph();
    g.dijkstra(1);
}
