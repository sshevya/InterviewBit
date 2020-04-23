/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
 
    if(A==NULL){
        return 0;
    }
    
    int lheight=minDepth(A->left);
    int rheight=minDepth(A->right);
    
    if(lheight==0){
        return 1+rheight;
    }else if(rheight==0){
        return 1+lheight;
    }else{
        return 1+min(lheight,rheight);
    }
    


}
