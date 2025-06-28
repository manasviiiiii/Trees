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

int ceil(TreeNode* root,int key){
    int cl;
    while(root!=NULL){
        if(root->val==key){
            cl=key;
            return cl;
        }
        else if(root->val>key){
           cl=root->val;
           root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return cl;
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
      cout<<ceil(root,11);
      
      return 0;
      
      
}