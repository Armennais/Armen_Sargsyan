#include <iostream>
#include <vector>
#include "graph.hpp"

using namespace std;

int main()
{
    srand(time(0));
    int size;
    cout << "Size: ";
    cin >> size;

    Graph *graph = new Graph(size);
    graph->printMatrix();

    graph->addDirectionalEdge(1, 2);
    graph->addEdge(3, 0);
    graph->addEdge(3, 1);
    graph->addEdge(3, 3);

    graph->addVertex();
    graph->addDirectionalEdge(3, 4);
    graph->printMatrix();
    graph->deleteEdge(3, 0);
    graph->deleteEdge(3, 4);
    graph->deleteVertex(4);
    graph->printMatrix();
    graph->nodeNeighbours(3);
    graph->nodeConnections(3);
    return 0;
}
