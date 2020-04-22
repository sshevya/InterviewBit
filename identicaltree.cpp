/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 int rec(TreeNode* A, TreeNode* B){
     
   
     if(!A || !B){
         return A==B;
     }
     
     
     if(A->val!=B->val){
         return 0;
     }else{
        
         return (rec(A->left,B->left) & rec( A->right,B->right)); 
         
         
     }
     
   }
     
 
 
 
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    
    if(rec(A,B)){
        return 1;
    }
    return 0;
    
}

