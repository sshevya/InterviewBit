/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int rec(TreeNode* A, int B){
     if(A==NULL){
         return 0;
     }
     
     int sum=0;
     if(B==A->val && A->left==NULL && A->right==NULL){
         return 1;
     }
     if(A->left){
        sum=sum||rec(A->left, B-A->val);
        
        
     }
     if(A->right){
         sum=sum||rec(A->right, B-A->val);
    
         
     }
     
     return sum;
     
 }
int Solution::hasPathSum(TreeNode* A, int B) {



    return rec(A,B);
}
