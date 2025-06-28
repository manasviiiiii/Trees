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

TreeNode* searchBST(TreeNode* root,int val){
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->val==val){
            return curr;
        }
        else if(curr->val>val){
            curr=curr->left;
        }
        else {
            curr = curr->right;
        }
    }
   return NULL; 
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
      if(searchBST(root,30)){
          cout<<"Found";
      } else {
          cout<<"Not Found";
      }
      
      return 0;
      
      
}