#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};
TreeNode* lca_bst(int p,int q ,TreeNode* root){
    if(root==NULL){
        return NULL;
    }
    TreeNode* curr = root;
    while(curr!=NULL){
        if(p<curr->val && q<curr->val){
            curr=curr->left;
        }else if (p>curr->val && q>curr->val){
            curr=curr->right;
        }else{
            return curr;
        }
    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    root->left = node1;
    node1->left = node2;
    node1->right = node3;
    node3->right=node4;
    root->right = node7;
    node7->left = node6;
    node7->right = node8;
    TreeNode* lca = lca_bst(1,6,root);
    cout<<lca->val<<" ";
}