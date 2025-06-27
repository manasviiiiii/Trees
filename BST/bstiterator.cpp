#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }



};

class BSTiterator {
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
    bool has_next(){
        return !st.empty();
    }

    int next(){
        if(has_next()){
            TreeNode* temp = st.top();
            st.pop();
            pushall(temp->right);
            return temp->val;
        }
        return -1;

    }


};

TreeNode* insert(TreeNode* root,int val){
    if(root==NULL){
        TreeNode* node = new TreeNode(val);
    }
    if(val<root->val){
        insert(root->left,val);
    }
    else{
        insert(root->right,val);
    }
return root;
}
int main (){
    TreeNode* root = NULL;
    vector<int>values={7,3,15,9,20};
    for(int val:values){
        root = insert(root,val);
    }
    BSTiterator it(root);
    cout<<"Elements in sorted order are:-";
    while(it.has_next()){
cout<<it.next()<<" ";
    }
cout<<endl;
return 0;
}