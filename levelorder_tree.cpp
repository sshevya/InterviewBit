/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int height(TreeNode* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the height of each subtree */
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  
        /* use the larger one */
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}  
 
void bfs(TreeNode* root, int level, vector<vector<int>> &v){
    if(root==NULL){
        return;
    }
    
        v[level].push_back(root->val);
    

        bfs(root->left,level+1,v);
        bfs(root->right,level+1,v);
    
}
 
 
 
 
 
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    int h=height(A);
    vector<vector<int>> v(h);
    
    bfs(A,0,v);
    return v;
}
