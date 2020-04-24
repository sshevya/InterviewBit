/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 //first check if the node exists as it is nnot given
 bool find(TreeNode* root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if ((root->left && find(root->left, val)) || 
        (root->right && find(root->right, val)))
        return true;
    return false;
}
 TreeNode* recur(TreeNode* A,int B,int C){
     if(A==NULL){
         return NULL;
     }
     if(A->val==B || A->val==C){
         return A;
     }
    /* don't compare values directly,wrong ans
     if(A->val > B && A->val <C || A->val>C && A->val <B){
         ans=A->val;
     }
     
     else if(A->val > B && A->val >C){
         recur(A->left,B,C,ans);
         
     }else {
         recur(A->right,B,C,ans);
     }
     */
     TreeNode* left=recur(A->left,B,C);
     TreeNode* right=recur(A->right,B,C);
     
     if(left && right){
         return A;
     }
     if(left){
         return left;
     }else{
         return right;
     }
     
 }
 
 
int Solution::lca(TreeNode* A, int B, int C) {
    TreeNode* ans;
     if (!find(A, B) || !find(A, C))
        return -1;
    ans=recur(A,B,C);
    if(ans){
    return ans->val;
    }else{
        return -1;
    }
}
