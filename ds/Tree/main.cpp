#include <iostream>
#include "BSTree.hpp"
int main()
{
    
    int size;
    cout << "Size: ";
    cin >> size;

    vector<int> nodes;
    int **matrix = new int *[size];

    cout << " ";
    for (int i = 0; i < size; i++)
    {
        cout << " " << i;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        cout << i << " ";
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Tree *root = new Tree();
    if (root->ancestorTree(matrix, size, nodes))
    {
        cout << "Is binary tree\n";
        cout << "root: " << root->root->_data << endl;
        for (int i = 0; i < nodes.size(); i++)
        {
            root->insert(nodes[i]);
        }
    }
    else
    {
        cout << "Is NOT binary tree\n";
    }

    // root->insertRecursive(4);
    // root->insertRecursive(6);
    // root->insertRecursive(10);
    // root->insertRecursive(9);
    // root->insertRecursive(8);
    // root->insertRecursive(12);
    // root->insertRecursive(11);
    // root->insertRecursive(13);
    // root->deleteNode(10);
    root->bfs();
    return 0;
}