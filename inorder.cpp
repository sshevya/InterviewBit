/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
 void rec(TreeNode* A, vector<int>& v){
     if(A==NULL){
         return;
     }
     rec(A->left,v);
     v.push_back(A->val);
     
     rec(A->right,v);
 }
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> v;
    if(A==NULL){
        return v;
    }
    rec(A,v);
    return v;
    
}
