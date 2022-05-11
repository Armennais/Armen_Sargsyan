#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph
{
private:
    int **adjMatrix;
    int _verticesCount;

public:
    Graph(int);
    void dijkstra(int);
    void printMatrix();
    void addEdge(int, int, int);
    int miniDist(int *, bool *);
};

Graph::Graph(int size)
{
    _verticesCount = size;
    adjMatrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        adjMatrix[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            adjMatrix[i][j] = INT_MAX;
        }
        adjMatrix[i][i] = 0;
    }
}

void Graph::printMatrix()
{
    cout << " ";
    for (int i = 0; i < _verticesCount; i++)
    {
        cout << " " << i;
    }
    cout << endl;
    for (int i = 0; i < _verticesCount; i++)
    {
        cout << i << " ";
        for (int j = 0; j < _verticesCount; j++)
        {
            if (adjMatrix[i][j] == INT_MAX)
            {
                cout << "∞";
            }
            else
            {
                cout << adjMatrix[i][j];
            }

            cout << " ";
        }
        cout << endl;
    }
}

void Graph::addEdge(int weight, int first, int second)
{
    adjMatrix[first][second] = weight;
    adjMatrix[second][first] = weight;
}

void Graph::dijkstra(int start)
{
    int distance[_verticesCount];
    bool isVisited[_verticesCount];

    for (int i = 0; i < _verticesCount; i++)
    {
        distance[i] = INT_MAX;
        isVisited[i] = false;
    }

    distance[start] = 0;

    for (int i = 0; i < _verticesCount; i++)
    {
        int m = miniDist(distance, isVisited);
        if (distance[m] == INT_MAX)
        {
            break;
        }
        for (int k = 0; k < _verticesCount; k++)
        {
            if (adjMatrix[m][k] != INT_MAX && distance[m] != INT_MAX && (distance[m] + adjMatrix[m][k]) < distance[k])
                distance[k] = distance[m] + adjMatrix[m][k];
        }
        isVisited[m] = true;
    }

    cout << "Distance: ";
    for (int j = 0; j < _verticesCount; j++)
    {
        cout << distance[j] << endl;
    }
}
int Graph::miniDist(int distance[], bool is_visited[]) // finding minimum distance
{
    int minimum = INT_MAX, ind;

    for (int k = 0; k < _verticesCount; k++)
    {
        if (!is_visited[k] && (minimum == INT_MAX || distance[minimum] > distance[k]))
        {
            minimum = distance[k];
            ind = k;
        }
    }

    return ind;
}
#endif // __DIJKSTRA_H__
