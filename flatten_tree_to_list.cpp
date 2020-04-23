/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void linkedlist(TreeNode* A){
    if(A==NULL){
        return ;
    }
    if(A->left==NULL && A->right==NULL){
        return ;
    }
    
    if(A->left){
        linkedlist(A->left);
        
        TreeNode* temp=A->right;
        A->right=A->left;
        A->left=NULL;
        
        TreeNode* t=A->right;
        while(t->right!=NULL){
            t=t->right;
        }
        
        t->right=temp;
        
    }
    linkedlist(A->right);
    
    
}

TreeNode* Solution::flatten(TreeNode* A) {
  
  
  linkedlist(A);
  
  return A;
  
  
}
