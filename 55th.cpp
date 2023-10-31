#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* Helper(vector<int>& nums,int s,int e){
        if(s>e)return NULL;
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=Helper(nums,s,mid-1);
        root->right=Helper(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Helper(nums,0,nums.size()-1);
    }
};
void display(TreeNode* &ans){
    if(ans==NULL)return;
    if(ans->left==NULL && ans->right==NULL){
        cout<<ans->val<<" ";
        return;
    }
    display(ans->left);
    cout<<ans->val<<"  ";
    display(ans->right);
}
bool searchBST(TreeNode* root,int key){
    //base case
    if (root==NULL)
    {
        /* code */
        return false;
    }
    if(root->val==key){
        return true;
    }
    
    //recursive case
    if (root->val<key)
    {
        /* code */
        return searchBST(root->right,key);
    }
    else if(root->val>key){
        return searchBST(root->left,key);
    }
    return false;
}
int main()
{
    Solution ss;
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-3);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(9);
    TreeNode* root=ss.sortedArrayToBST(nums);
    display(root);
    cout<<endl;
    cout<<"Searching element 5: ";
    bool temp=searchBST(root,5);
    cout<<temp<<endl;
    cout<<"Searching element 15: ";
    temp=searchBST(root,15);
    cout<<temp<<endl;
   return 0;
}