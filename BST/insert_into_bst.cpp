// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int data){
        val = data;
    }
};

TreeNode* insertintoBST (TreeNode* root,int val){
    if(root==NULL){
        TreeNode* node = new TreeNode(val);
        return node;
    }
    TreeNode* curr = root;
    while(true){
        if(root->val>val){
            if(root->left!=NULL){
                root = root->left;
            }else{
                TreeNode* node = new TreeNode(val);
                root->left = node;
                break;
            }
        }
        else {
            if(root->right!=NULL){
                root = root->right;
            }else{
                TreeNode* node = new TreeNode(val);
                root->right = node;
                break;
            }
        }
    }
    return curr;
    
}
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
    TreeNode* root = new TreeNode(8);
    TreeNode* node1 = new TreeNode(3);
     TreeNode* node2 = new TreeNode(10);
      TreeNode* node3 = new TreeNode(1);
      TreeNode* node4 = new TreeNode(6);
      TreeNode* node5 = new TreeNode(14);
      TreeNode* node6 = new TreeNode(13);
      TreeNode* node7 = new TreeNode(4);
      TreeNode* node8 = new TreeNode(7);
      root->left = node1;
      root->right = node2;
      node1->left = node3;
      node1->right = node4;
      node4->left=node7;
      node4->right=node8;
      node2->right=node5;
      node5->left = node6;
      inorder(root);
      cout<<endl;
     TreeNode* node = insertintoBST(root,9);
     inorder(node);
      
      return 0;
      
      
}