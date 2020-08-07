/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 bool rec(TreeNode* A, int B, vector<int> &v){
    if(A==NULL){
        return false;
    }
    
    
     if(A->val==B){
         v.push_back(B);
         return true;
     }
     v.push_back(A->val);
     if(rec(A->left,B,v)){
         return true;
     }else if(rec(A->right,B,v)){
         return true;
     }
        else{
            
        v.pop_back();
            return false ;

        }
    
 }
 
 
 
 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int> v;
    rec(A,B,v);
    return v;
}
