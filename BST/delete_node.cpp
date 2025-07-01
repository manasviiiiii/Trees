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
void inorder(TreeNode* root){
    if(root==NULL){return;}
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

TreeNode* find_right_most(TreeNode* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
    
}
TreeNode* helper(TreeNode* root){
    if(root->left==NULL){
        return root->right;
    }
    if(root->right==NULL){
        return root->left;
    }
    TreeNode* leftchild= root->left;
    TreeNode* rightmost = find_right_most(leftchild);
    rightmost->right=root->right;
    return leftchild;
}


TreeNode* delete_Node (TreeNode* root , int key){
    if(root==NULL){
        return root;
    }
    if(root->val==key){
        return helper(root);
    }
    TreeNode* dummy = root;
    while(root!=NULL){
    if(root->val>key){
        if(root->left!=NULL && root->left->val==key){
            root->left=helper(root->left);
            break;
        }
        else{
            root=root->left;
        }
    }else{
        if(root->right!=NULL && root->right->val==key){
           root->right= helper(root->right);
            break;
        }else{
            root=root->right;
        }
    } }
    return dummy;
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
    inorder(root);
     root = delete_Node(root,5);
     cout<<endl;
    inorder(root);
}