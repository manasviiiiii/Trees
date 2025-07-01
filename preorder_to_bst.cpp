#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* build(vector<int>& preorder ,int &i  , int bound){
    if(i==preorder.size() || preorder[i]>bound){
        return NULL;}
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    
}
TreeNode* bstfrompreorder (vector<int>& preorder){
    int i=0;
    return build(preorder,i,INT_MAX);
    
}
void inorder(TreeNode* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    
}
int main(){
    vector<int>preorder={5,2,1,3,4,7,6,8};
    TreeNode* root = bstfrompreorder(preorder);
    inorder(root);
    return 0; }
    