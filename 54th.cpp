#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void insertintobst(node* &root, int data){
    if(root == NULL){
        root = new node(data);
        return;
    }
    if(data <= root -> data){
        if(root -> left == NULL){
            root -> left = new node(data);
        }
        else{
            insertintobst(root -> left, data);
        }
    }
    else{
        if(root -> right == NULL){
            root -> right = new node(data);
        }
        else{
            insertintobst(root -> right, data);
        }
    }
}

int minimum(node* root){
    while(root -> left){
        root = root -> left;
    }
    return root -> data;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main(){
    node* root = NULL;
    int n;
    cin >> n;
    int d;
    for(int i = 0; i < n; i++){
        cin >> d;
        insertintobst(root, d);
    }
    cout << "Minimum value in BST is: " << minimum(root) << endl;
    cout << "In-order traversal of the given tree is: ";
    inorder(root);
    return 0;
}