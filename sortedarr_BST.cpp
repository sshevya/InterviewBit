/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //use const vector and not vector, otherwise itll show TLE
TreeNode* BST(int start, int end,const vector<int>& A){
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    
     TreeNode* root=new TreeNode(A[mid]);
    
    root->left=BST( start,mid-1,A);
    root->right=BST(mid+1,end,A);
    
    
    return root;
    
}



TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
  
    
    return BST(0,A.size()-1,A);
    
    
    
    
    
}
