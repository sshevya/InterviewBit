/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 //dont just check for diff bet left and right tree of root you have to do it at every level
 //
 
 int getheight(TreeNode* temp){
     

     if(temp==NULL){
         return 0;
     }
     if(temp->left==NULL && temp->right==NULL){
         return 1;
     }
     int hleft=getheight(temp->left);
     int hright=getheight(temp->right);
     
     if(hleft<0 || hright<0){
         return INT_MIN;
     }
     
     if(abs(hleft-hright)>1){
         return INT_MIN;
     }
     return 1+max(hleft,hright);
     
 }
 
 
int Solution::isBalanced(TreeNode* A) {
    
    if(getheight(A)<0){
        return 0;
    }
    
    
    
    return 1;
    
    
    
    
    

}
