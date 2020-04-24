/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void Mirror(TreeNode* A){
    if(A==NULL){
        return;
    }
    
    Mirror(A->left);
    Mirror(A->right);
    
    TreeNode* temp=A->left;
    A->left=A->right;
    A->right=temp;
    //free(temp);
}
 
 
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL){
         return NULL;
    }
    Mirror(A);
    
    return A;
}
