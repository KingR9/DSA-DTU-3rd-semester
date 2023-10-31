#include<iostream>
using namespace std;

class node
{
public:
    char value; // value of the node
    node* left; // pointer to the left child of the node
    node* right; // pointer to the right child of the node
};

node* newNode(char value)
{
    node* temp = new node();
    temp->value = value;
    temp->left = temp->right = nullptr;
    return temp;
}

void printInorder(node* root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

void printPostorder(node* root)
{
    if (root == nullptr)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->value << " ";
}

int main()
{
    node* root = newNode('+');
    root->left = newNode('*');
    root->right = newNode('-');
    root->left->left = newNode('A');
    root->left->right = newNode('B');
    root->right->left = newNode('C');
    root->right->right = newNode('D');

    cout << "Inorder traversal of binary expression tree: ";
    printInorder(root);

    cout << "\nPostorder traversal of binary expression tree: ";
    printPostorder(root);

    return 0;
}