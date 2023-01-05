#include <iostream>
#include <sstream>

using namespace std;

void List(string ref)
{
    cout << ref << " | ";
}

int main()
{

    //Get size of array
    int nV; //number of Vertices
    string v1, v2; // holds labels
    string num; // holds weight
    cout << "Enter number of vertices: ";
    cin >> nV;
    string matrix[nV+1][nV+1]; // +1 to hold a row and column for vertex labels

    //insert names into array
    string labels[nV];
    string name;
    cout << "Label the Vertices with a space in between:" << endl;
    for(int i = 0; i < nV; i++)
    {
        cin >> name;
        labels[i] = name;
    }

    //creating matrix
    matrix[0][0] = " "; //index 0,0 will be empty space
    for(int i = 0; i < nV; i++)
    {
        matrix[0][i+1] = labels[i]; // fills first row with vertices
        matrix[i+1][0] = labels[i]; // fills first column with vertices
    }
    
    //fills matrix with weight 0
    for(int x = 1; x <= nV; x++)
    {
        for(int y = 1; y <= nV; y++)
        {
            matrix[x][y] = "0";
        }
    }

  
    //ask user to define edges and weight
    cout << "Define Edges with weight." << endl;
    for(int i = 0; i < nV; i++)
    {
        cout << "Enter first vertex, second vertex, and a weight with a space in between, e.g. A B 3: " << endl;
        cin >> v1 >> v2 >> num;

        //Check for invalid vertices
        int j = 0;
        while(v1 != labels[j])
        {
            if(j >= nV)
            {
                cout << "Error, invalid Vertex.";
                return -1;
            }
            j++;
        }
        j = 0;
        while(v2 != labels[j])
        {
            if(j >= nV)
            {
                cout << "Error, invalid Vertex.";
                return -1;
            }
            j++;
        }

        //insert weight into matrix
        for(int x = 1; x <= nV; x++)
        {
            for(int y = 1; y <= nV; y++)
            {
                if(v1 == matrix[0][x])
                {
                    if(v2 == matrix[y][0])
                    {
                        matrix[y][x] = num;
                        matrix[x][y] = num; //(Assuming that the graph is undirected)
                    }
                }
            }

        }
    }
   
    cout << endl;

    //print out matrix
    for(int x = 0; x <= nV; x++)
    {
        for(int y = 0; y <= nV; y++)
        {
            List(matrix[x][y]);
        }
        cout << endl;
    }
    return 0;
}