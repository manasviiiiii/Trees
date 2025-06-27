#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
    
};
bool validate_helper(TreeNode* root , long mini,long maxi){
    if(root==NULL){
        return true;
    }
    if(root->val<mini || root->val>maxi){
        return false;
    }
    return validate_helper(root->left,mini,root->val) && validate_helper(root->right,root->val,maxi);
}

bool validate_BST(TreeNode* root){
    
    return validate_helper(root,LONG_MIN,LONG_MAX);
}
int main(){
    /* 10
       / \
       5  15
       /\  \
       4 7  20
       
       
       */
    TreeNode* root = new TreeNode(10);
    TreeNode* node1 = new TreeNode(5);
    root->left = node1;
    TreeNode* node2 = new TreeNode(15);
    root->right = node2;
    TreeNode* node3 = new TreeNode(4);
    node1->left = node3;
    TreeNode* node4 = new TreeNode(7);
    node1->right = node4;
    TreeNode* node5 = new TreeNode(20);
    node2->right = node5;
     if(validate_BST(root)){
         cout<<"True, it is a BST";
         
     }else {
         cout<<"Not a BST";
     }
    
    
    return 0;
}
