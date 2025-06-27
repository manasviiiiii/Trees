#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
class BSTiterator{
    private:
    stack<TreeNode*>st;
    void pushall(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            node = node->left;
        }
    }
    public:
    BSTiterator(TreeNode* root){
        pushall(root);
    }
    int next(){
        TreeNode* temp =  st.top();
        st.pop();
        pushall(temp->right);
        return temp->val;
    }
    bool has_next(){
        return !st.empty();
    }
    
};
TreeNode* insert(TreeNode* root,int val){
    if(root==NULL){
        TreeNode* node = new TreeNode(val);
        return node;
        
    }
    if(val<root->val){
      root->left =insert(root->left,val);
    }else {
        root->right = insert(root->right,val);
    }
    
    return root;
}
int main(){
    TreeNode*  root = NULL;
    vector<int>values={7,3,15,9,20};
    for(auto val:values){
        root=insert(root,val);
    }
    BSTiterator it(root);
    cout<<"BST in sorted order is:-";
    while(it.has_next()){
        cout<<it.next()<<" ";
        
    }
    cout<<endl;
    return 0;
}

