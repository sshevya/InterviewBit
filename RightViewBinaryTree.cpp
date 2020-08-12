/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void rightViewUtil(TreeNode *root,  int level, int *max_level, vector<int> & v) 
{ 
    // Base Case 
    if (root == NULL) return; 
  
    // If this is the last Node of its level 
    if (*max_level < level) 
    { 
        v.push_back(root->val);
        *max_level = level; 
    } 
  
    // Recur for right subtree first,  
    // then left subtree 
    rightViewUtil(root->right, level + 1, max_level,v); 
    rightViewUtil(root->left, level + 1, max_level,v); 
} 
vector<int> Solution::solve(TreeNode* A) {
    
    vector<int> v;
  int max_level = 0; 
    rightViewUtil(A, 1, &max_level,v); 
    
    
    
    return v;
}
