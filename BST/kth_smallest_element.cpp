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
class BSTiterator{
    private:
    stack<TreeNode*>st;
    void pushall(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        
    }
    public:
    BSTiterator(TreeNode* root){
        pushall(root);
    }
    int next(){
        TreeNode* node = st.top();
        st.pop();
        pushall(node->right);
        return node->val;
        
    }
    bool has_next(){
        return !st.empty();
    } };
    int kth_smallest_element(TreeNode* root,int k){
        int cnt=0;
        BSTiterator it(root);
        while(it.has_next()){
            cnt++;
            int n= it.next();
            if(cnt==k){
                return n;
            }
        }
        return 0;
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
    int k= 8;
    cout<<kth_smallest_element(root,k);
    return 0;}
    
    
    
    
    
    
    
    
    