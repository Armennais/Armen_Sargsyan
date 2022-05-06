#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    vector<vector<int>> adjMatrix;

public:
    Graph(int);
    void addVertex();
    void addEdge(int, int);
    void addDirectionalEdge(int, int);
    void deleteVertex(int);
    void deleteEdge(int, int);
    void deleteDirectionalEdge(int, int);
    void printMatrix(); // DONE
    bool isConnected(int, int);
    void nodeNeighbours(int);
    void nodeConnections(int);
};

Graph::Graph(int size)
{
    for (int i = 0; i < size; i++)
    {
        adjMatrix.push_back(vector<int>());
        for (int j = 0; j < size; j++)
        {
            adjMatrix[i].push_back(0);
        }
    }
}

void Graph::addVertex()
{
    adjMatrix.push_back(vector<int>());
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        adjMatrix[adjMatrix.size() - 1].push_back(0);
    }
}

void Graph::printMatrix()
{
    cout << " ";
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        cout << " " << i;
    }
    cout << endl;
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        cout << i << " ";
        for (int j = 0; j < adjMatrix.size(); j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool Graph::isConnected(int first, int second)
{
    return adjMatrix[first][second] == 1 && adjMatrix[second][first] == 1;
}

void Graph::addEdge(int first, int second)
{
    adjMatrix[first][second] = 1;
}

void Graph::addDirectionalEdge(int first, int second)
{
    adjMatrix[first][second] = 1;
    adjMatrix[second][first] = 1;
}

void Graph::deleteEdge(int first, int second)
{
    adjMatrix[first][second] = 0;
}

void Graph::deleteDirectionalEdge(int first, int second)
{
    adjMatrix[first][second] = 0;
    adjMatrix[second][first] = 0;
}

void Graph::deleteVertex(int vertex)
{
    adjMatrix.erase(adjMatrix.begin() + vertex);
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        adjMatrix[i].erase(adjMatrix[i].begin() + vertex);
    }
}

void Graph::nodeNeighbours(int vertex)
{
    cout << "The node neighbours: ";
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[vertex][i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void Graph::nodeConnections(int vertex)
{
    // TODO
    int tempVertex = 0;
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[vertex][i] == 1 && adjMatrix[vertex][i])
        {
            cout << i << " ";
            nodeConnections(i);
        }
        }
    cout << endl;
}

#endif // __GRAPH_H__