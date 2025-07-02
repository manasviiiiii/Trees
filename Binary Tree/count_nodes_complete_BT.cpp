#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val=value;
        left=NULL;
        right=NULL;
    }
    
};
int find_left_height(TreeNode* root){
    int cnt=0;
    while(root!=NULL){
        root=root->left;
        cnt++;
    }
    return cnt;
    
    
}
int find_right_height(TreeNode* root){
    int cnt=0;
    while(root!=NULL){
        root=root->right;
        cnt++;
    }
    return cnt;
    
}
int countNodes(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int lh = find_left_height(root);
    int rh = find_right_height(root);
    if(lh==rh){
        return (1<<lh)-1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


   
     int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    
   
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    
    root->left = node1;
    node1->left = node2;
    node1->right = node3;
    
    root->right = node7;
    node7->left = node6;
    
    cout<<countNodes(root);
    return 0;
     }
    
    