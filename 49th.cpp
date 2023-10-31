#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void topView(Node *root)
{
    if (root == NULL) return;
   
    map<int, int> topViewMap;
    queue<pair<Node*, int> > q;
 
    int hd = 0;
    q.push({root, hd});
 
    while (q.empty() == false)
    {
        Node* node = q.front().first;
        hd = q.front().second;
        q.pop();
 
        topViewMap[hd] = node->data;
 
        if (node->left != NULL)
            q.push({node->left, hd-1});
        if (node->right != NULL)
            q.push({node->right, hd+1});
    }
 
    for (auto i = topViewMap.begin(); i != topViewMap.end(); ++i)
        cout << i->second << " ";
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->right->right = newNode(10);
    cout << "Top view of the tree is \n";
    topView(root);
    return 0;
}