#include <iostream>
#include "BSTree.hpp"
int main()
{
    // int n = 3;
    // int arr[3][3] = {
    //     {0,1,1},
    //     {0,0,0},
    //     {1,0,0}
    // };
    // Tree * root;
    // if(root->ancestorTree(arr,n))
    // {
    //     cout << "is binary Tree";
    // }else{
    //     cout << "is not binary tree \n";
    // }

    Tree * root = new Tree(5);
    root->insertRecursive(3);
    root->insertRecursive(8);
    root->insertRecursive(1);
    root->insertRecursive(4);
    root->insertRecursive(7);
    root->insertRecursive(9);
    root->dfs();
    cout << endl;
    root->deleteNode(9);
    root->dfs();
    return 0;
}