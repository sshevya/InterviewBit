/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void rec(TreeNode* A, int B, vector<int>& sol, vector<vector<int>> &ans){
     
    

     if(B==0 && A->left==NULL && A->right==NULL){
         
         //if(find(ans.begin(),ans.end(),sol)==ans.end()){
         ans.push_back(sol);
         
     }
     
     if(A->left){
         sol.push_back(A->left->val);
     rec(A->left,B-A->left->val,sol,ans);
     sol.pop_back();
     }
     if(A->right){
        sol.push_back(A->right->val);
     rec(A->right,B-A->right->val,sol,ans);
     sol.pop_back();
     }
     
 }
 

 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int>> v;
    vector<int> sol;
    if(A==NULL){
        return v;
    }
         sol.push_back(A->val);

    rec(A,B-A->val,sol,v);
    
    
    return v;
}
