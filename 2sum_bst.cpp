/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void rec(TreeNode* A,int B,unordered_map<int,int>& m,int& ans){
     
     if(A==NULL){
         return ;
     }
    
     if(m.find(B-A->val)!=m.end()){
         //if(m[B-A->val]!=m[A->val])
         ans=1;
     }
          m[A->val]=1;

     if(A->left){
         rec(A->left,B,m,ans);
     }
     if(A->right){
         rec(A->right,B,m,ans);
     }
     
     
     
 }
 
 
 
int Solution::t2Sum(TreeNode* A, int B) {
    
    
    if(A==NULL){
        return 0;
    }
    unordered_map<int,int> m;
    int ans=0;
    rec(A,B,m,ans);
    return ans;
}
