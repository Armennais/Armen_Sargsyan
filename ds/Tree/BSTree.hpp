#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <iostream>
#include <vector>
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
    void _dfs(Node *_root)
    {
        if (_root == NULL)
            return;
        _dfs(_root->_left);
        cout << _root->_data << " ";
        _dfs(_root->_right);
    }

public:
    Node *root;
    Tree(int);
    Tree()
    {
    }
    bool search(int);
    void deleteNode(int value);
    void insert(int);
    bool ancestorTree(int **, int, vector<int> &);
    int getMatrixRoot(int **, int);
    void insertRecursive(int value)
    {
        root->insertRecursive(value);
    }
    void bfs();
    void dfs();
};

int Tree::getMatrixRoot(int **arr, int n)
{
    int a = 0;
    int root;
    bool checkToStop = false;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == 0)
            {
                count++;
            }
            if (count == n)
            {
                a++;
                if (a > 1)
                {
                    checkToStop = false;
                }
                else
                {
                    checkToStop = true;
                    root = i;
                }
            }
        }
    }

    return checkToStop ? root : -1;
}

bool Tree::ancestorTree(int **arr, int n, vector<int> &nodes)
{
    int getRoot = getMatrixRoot(arr, n);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
            if ((arr[i][j] == 1 && arr[j][i] == 1) || getRoot == -1)
            {
                return false;
            }
            if (arr[i][j] == 1)
            {
                nodes.push_back(j);
            }
        }
        if (count > 2)
        {
            return false;
        }
    }

    root = new Node(getRoot);

    return true;
}

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

void Tree::deleteNode(int value)
{
    if (!root)
    {
        return;
    }

    Node *current = root;
    Node *prev = NULL;

    while (current != NULL && current->_data != value)
    {
        prev = current;
        if (value < current->_data)
        {
            current = current->_left;
        }
        else
        {
            current = current->_right;
        }
    }

    if (current->_left == NULL || current->_right == NULL)
    {
        Node *newCurrent = (current->_left == NULL) ? current->_right : current->_left;

        if (current == prev->_left)
        {
            prev->_left = newCurrent;
        }
        else
        {
            prev->_right = newCurrent;
        }
    }
    else
    {
        Node *min = NULL;
        Node *temp = current->_right;

        while (temp->_left != NULL)
        {
            min = temp;
            temp = temp->_left;
        }

        if (min == NULL)
        {
            current->_right = temp->_right;
        }
        else
        {
            min->_left = temp->_right;
        }

        current->_data = temp->_data;
    }
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

void Tree::insert(int value)
{
    if (!root)
    {
        return;
    }

    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Node *current = queue.front();
        queue.pop();

        if (current->_left)
        {
            queue.push(current->_left);
        }
        else
        {
            current->_left = new Node(value);
            break;
        }

        if (current->_right)
        {
            queue.push(current->_right);
        }
        else
        {
            current->_right = new Node(value);
            break;
        }
    }
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