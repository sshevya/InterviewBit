/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
////First method
 
void inorder(TreeNode* A, vector<int> & v, int B,int& ans){
    if(A==NULL){
        return;
    }
    inorder(A->left,v,B,ans);
    v.push_back(A->val);
    if(v.size()==B){
        ans=v[B-1];
        return;
    }
    inorder(A->right,v,B,ans);
    
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    
    if(A==NULL){
        return 0;
    }
    int p=0;
    vector<int> v;
    
    
    int ans=-1;
    inorder(A,v, B, ans);
    return ans;       
}
///Second Method
 
 //pass value of count with address otherwise error
TreeNode* rec(TreeNode* A, int B, int& count){
    if(A==NULL){
        return NULL;
    }
    
    TreeNode* left=rec(A->left,B,count);
    if(left!=NULL){
        return left;
    }
    ++count;
    if(count==B){
        return A;
    }
    return rec(A->right,B,count);
    
    
}
 
 
int Solution::kthsmallest(TreeNode* A, int B) {
    
    if(A==NULL){
        return 0;
    }
    int p=0;
    TreeNode* node=rec(A,B,p);
    
    if(node!=NULL){
        return node->val;
    }
}
