/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int rec(TreeNode* A, int val){
    if(A==NULL){
        return 0;
    }
    val=(((val%1003)*10)%1003+(A->val)%1003)%1003;
    if(A->left==NULL && A->right==NULL){
    return val%1003;
    }
    
    return (rec(A->left,val)%1003+rec(A->right,val)%1003)%1003;
 }
 
 
int Solution::sumNumbers(TreeNode* A) {
    
   
 return rec(A,0);   

    
    
    
    
}
