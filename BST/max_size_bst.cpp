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

class NodeValue{
    public:
    int maxi;
    int mini;
    int max_size;
    NodeValue(int maxi,int mini,int max_size){
        this->maxi=maxi;
        this->mini=mini;
        this->max_size=max_size;
    }
    
};

NodeValue largestBSThelper(TreeNode* root){
    if(root==NULL){
        return {INT_MIN,INT_MAX,0};
    }
    auto left = largestBSThelper(root->left);
    auto right = largestBSThelper(root->right);
    if(root->val>left.maxi && root->val<right.mini){
        return {max(root->val,right.maxi),min(root->val,left.mini), 1+
        left.max_size + right.max_size};
    }
    return {INT_MAX,INT_MIN,max(left.max_size,right.max_size)};
}

int largestBST (TreeNode* root){
    return largestBSThelper(root).max_size;
}
    
   
     int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(0);
   
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
    cout<<largestBST(root);
    return 0;
     }
    
    