class Solution {
public:
    
    bool rec(TreeNode* root, int target){
    if(root==NULL){
        return 0;
    }
        int val = target-root->val;

        
        bool ans=false;
        if(val==0 && root->left==NULL && root->right==NULL){
            return true;
        }
        
        
        if(root->left){
        ans=ans||rec(root->left, val);
        }
        if(root->right){
            

        ans=ans||rec(root->right,val);
        }        
        return ans;
       
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        
        return rec(root,targetSum);
        
    }
};
