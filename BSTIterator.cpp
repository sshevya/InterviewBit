/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
void inorder(TreeNode* root,vector<int>& v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
    
}*/
stack<TreeNode*> s;
TreeNode*  temp=NULL;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!s.empty()){
        s.pop();
    }
    temp=root;
    while(temp){
        s.push(temp);
        temp=temp->left;
        
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(!s.empty()){
        return true;
    }return false;
    
    

}

/** @return the next smallest number */
int BSTIterator::next() {
    if(s.empty()){
        return -1;
    }
    temp=s.top();
    int ans=temp->val;
    temp=temp->right;
    s.pop();

    while(temp){
        s.push(temp);
        temp=temp->left;
    }


return ans;


}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
