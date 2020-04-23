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
     v.push_back(A->val);

     rec(A->left,v);
     
     rec(A->right,v);

 }




 
vector<int> Solution::preorderTraversal(TreeNode* A) {
           vector<int> v;
    if(A==NULL){
        return v;
    }
    rec(A,v);
    return v;
}
