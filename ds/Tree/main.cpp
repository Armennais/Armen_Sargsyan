#include <iostream>
#include "BSTree.hpp"
int main()
{
    Tree * root = new Tree(5);

    root->insertRecursive(4);
    root->insertRecursive(6);
    root->insertRecursive(3);
    root->insertRecursive(5);
    root->insertRecursive(5);
    root->insertRecursive(7);
    root->dfs();
    return 0;
}