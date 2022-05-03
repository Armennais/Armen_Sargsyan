#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int _data;
    Node *_left;
    Node *_right;

    Node(int data)
    {
        _data = data;
        _left = nullptr;
        _right = nullptr;
    }
    void insertRecursive(int);
};

class Tree
{
    private:
    Node *root;
    void _dfs(Node *_root)
    {
        if (_root == NULL)
            return;
        _dfs(_root->_left);
        cout << _root->_data << " ";
        _dfs(_root->_right);
    }

public:
    Tree(int);
    bool search(int);
    void insertRecursive(int value){ root->insertRecursive(value); }
    void bfs();
    void dfs();
};

Tree::Tree(int value)
{
    root = new Node(value);
}

bool Tree::search(int value)
{
    if (root == NULL)
    {
        return false;
    }

    while (root != NULL)
    {
        if (value > root->_data)
        {
            root = root->_right;
        }
        else
        {
            root = root->_left;
        }
        if (root->_data == value)
        {
            return true;
        }
    }

    return false;
}

void Tree::bfs()
{
    queue<Node *> q;
    if (root)
    {
        q.push(root);
        cout << root->_data << " ";
    }

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        if (root->_left)
        {
            q.push(root->_left);
            cout << root->_left->_data << " ";
        }

        if (root->_right)
        {
            q.push(root->_right);
            cout << root->_right->_data << " ";
        }
    }
}

void Tree::dfs()
{
    if (root == NULL)
        return;
    _dfs(root->_left);
    cout << root->_data << " ";
    _dfs(root->_right);
}


void Node::insertRecursive(int value)
{
    if (_data > value)
    {
        if (_left)
        {
            _left->insertRecursive(value);
        }
        else
        {
            _left = new Node(value);
        }
    }
    else
    {
        if (_right)
        {
            _right->insertRecursive(value);
        }
        else
        {
            _right = new Node(value);
        }
    }
}
#endif // __BSTREE_H__