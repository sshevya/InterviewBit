/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* removeNode(TreeNode* A, TreeNode* parent){
    if(A==NULL){
        return NULL;
    }
    
    if(A->left==NULL && A->right==NULL){
        return A;
    }
    
        A->left=removeNode(A->left,A);
        A->right=removeNode(A->right,A);
    
    if(A->left==NULL){
        
            TreeNode* temp=A->right;
            
            return temp;
            
    }
    if(A->right==NULL){
        TreeNode* temp=A->left;
    
        return temp;
    }
    
    
    return A;
    
}
 
 
 
 
 
TreeNode* Solution::solve(TreeNode* A) {
    A=removeNode(A,NULL);
    return A;
}
