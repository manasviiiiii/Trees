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
int predecessor(TreeNode* root,int key){
    int prede=-1;
    if(root==NULL){
        return prede;
    }
    while(root!=NULL){
        if(root->val<key){
            prede = root->val;
            root = root->right;
        }
        else {
            root=root->left;
        }
    }
    return prede;
}
int successor(TreeNode* root,int key){
    int succ=-1;
    if(root==NULL){
        return succ;
    }
    while(root!=NULL){
        if(root->val>key){
            succ=root->val;
            root=root->left;
        }else{
            root=root->right;
        }
    }return succ;
    
}
vector<int>successesor_prdecessor(TreeNode* root,int key){
    return {predecessor(root,key),successor(root,key)};
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
    vector<int>ans;
    ans = successesor_prdecessor(root,8);
    cout<<ans[0]<<" "<<ans[1];
}
