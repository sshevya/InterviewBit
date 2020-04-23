/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    
    int lheight=maxDepth(A->left);
    int rheight=maxDepth(A->right);
    
    return 1+max(lheight,rheight);
    
}
