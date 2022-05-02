#include <iostream>
#include <queue>
#include <climits>
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
};
void InsertNode(Node* root, int data);
int findMaxNode(Node* root);
int findMinNode(Node* root);
void _dfs(Node *root);
void _bfs(Node *root);
int main()
{
    Node *root = new Node(50);
    root->_left = new Node(10);
    root->_right = new Node(3);

    root->_left->_left = new Node(4);
    root->_left->_right = new Node(30);
    root->_left->_left->_left = new Node(25);

    root->_right->_right = new Node(100);
    root->_right->_right->_left = new Node(50);
    root->_right->_right->_right = new Node(200);

    // _bfs(root);
    // _dfs(root);
    InsertNode(root, 1500);
    _bfs(root);
    cout << endl;
    cout << "Maximum number of Tree is: ";
    cout  << findMaxNode(root) << endl;
    cout << "Minimum number of Tree is: ";
    cout << findMinNode(root);
    return 0;
}
//Find Maximal Node
int findMaxNode(Node* root) {
   
   if (root == NULL)
   {
      return -1;
   }
   int maxVal = root->_data;
   int leftMin = findMaxNode(root->_left);
   int rightMin = findMaxNode(root->_right);
   if (leftMin > maxVal)
      maxVal = leftMin;
   if (rightMin > maxVal)
      maxVal = rightMin;
   return maxVal;
}
//Find Minimal Node
int findMinNode( Node* root)
{
    if(root == NULL) {  
        return 0;  
    }  
    else{  
        int leftMin, rightMin;  
        int min = root->_data;  
        if(root->_left != NULL){  
            leftMin = findMinNode(root->_left);  
            min = (min > leftMin) ? leftMin : min;  
        }  
        if(root->_right != NULL){  
            rightMin = findMinNode(root->_right);  
            min = (min > rightMin) ? rightMin : min;  
        }  
    return min;  
    }  
}

//Breadth First Search
void _bfs(Node *root)
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

//Depth First Search:
void _dfs(Node *root)
{
    if (root == NULL)
        return;
    _dfs(root->_left);
    cout << root->_data << " ";
    _dfs(root->_right);
}

void InsertNode(Node* root, int data)
{
    if (root == NULL) {
        root = new Node(data);
        return;
    }
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->_left != NULL)
            q.push(temp->_left);
        else {
            temp->_left = new Node(data);
            return ;
        }
 
        if (temp->_right != NULL)
            q.push(temp->_right);
        else {
            temp->_right = new Node(data);
            return ;
        }
    }
}