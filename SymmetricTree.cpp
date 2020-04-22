/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int check(TreeNode* A, TreeNode* B){
    
    if(A==NULL && B==NULL){
        return 1;
    }
    
    if(A&& B&& A->val==B->val){
        return check(A->left,B->right)&& check(B->left,A->right);
    }
    return 0;
}
         

int Solution::isSymmetric(TreeNode* A) {
    
    
    
    return check(A,A);
    
}
