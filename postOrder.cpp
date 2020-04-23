/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 void rec(TreeNode* A, vector<int>& v){
     if(A==NULL){
         return;
     }
     rec(A->left,v);
     
     rec(A->right,v);
     v.push_back(A->val);

 }


vector<int> Solution::postorderTraversal(TreeNode* A) {
       vector<int> v;
    if(A==NULL){
        return v;
    }
    rec(A,v);
    return v;
}
