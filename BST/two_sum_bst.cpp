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
class BSTiterator{
    private:
    stack<TreeNode*>st;
    bool reverse;
    void pushall(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(reverse){
                root=root->right;
            }else{
            root=root->left;
            }
        }
    }
    public:
    BSTiterator(TreeNode* root,bool r){
        reverse=r;
        pushall(root);
    }
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(reverse){
            pushall(temp->left);
        }else{
       pushall(temp->right);}
       return temp->val;
    }
    
    bool has_next(){
        return !st.empty();
    }
    
};
bool two_sum_bst(TreeNode* root,int k){
    if(root==NULL){
        return false;
    }
    BSTiterator l(root,false);
    BSTiterator r(root,true);
    auto i=l.next();
    auto j = r.next();
    while(i<j){
        if(i+j==k){
            return true;
        }
        else if(i+j<k){
            i=l.next();
        }else{
            j=r.next();
        }
    }
   return false; 
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
    cout<<two_sum_bst(root,9);
}
