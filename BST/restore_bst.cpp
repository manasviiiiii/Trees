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
void helper_restoreBST(TreeNode* root , TreeNode* &first,TreeNode* &middle , TreeNode* &last , TreeNode* &prev){
    if(root==NULL){
        return;
    }
    helper_restoreBST(root->left,first,middle,last,prev);
    if(prev!=NULL && (prev->val>root->val)){
        if(first==NULL){
            first=prev;
            middle=root;
            
        }else{
            last=root;
        }
    }
    prev=root;
    helper_restoreBST(root->right,first,middle,last,prev);
    
    }
void restoreBST(TreeNode* root){
    TreeNode* first = NULL;
    TreeNode* middle=NULL;
    TreeNode* last= NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    helper_restoreBST(root,first,middle,last,prev);
    if(first && last){
        swap(first->val,last->val);
    }else{
        swap(first->val,middle->val);
    }
    
}

    
    void inorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->val;
        inorder(root->right);
    }
     int main(){
    TreeNode* root = new TreeNode(8);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
   
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(5);
    root->left = node1;
    node1->left = node2;
    node1->right = node3;
    node3->right=node4;
    root->right = node7;
    node7->left = node6;
    node7->right = node8;
    inorder(root);
    restoreBST(root);
    cout<<endl;
    inorder(root);
     }
    