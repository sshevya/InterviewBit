/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 //use vector with & otherwise TLE
 
 
int searchindex(const vector<int>& v,int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(v[i]==val){
            return i;
        }
    }
} 
 
 
TreeNode* rec(const vector<int>& in,const  vector<int>& post, int start, int end, int& pindex){
    
    if(start>end){
        return NULL;
    }
   TreeNode* root=new TreeNode(post[pindex]) ;
   pindex--;
   
   if(start==end){
       return root;
   }
   
   
   
   
   int index=searchindex(in,start,end,root->val);
   //allot right node first otherwise different answer;
      root->right=rec(in,post,index+1,end,pindex);

   root->left=rec(in,post,start, index-1, pindex);
    return root;
    
}
 
 
 
 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    int p=    A.size()-1;
    return rec(A,B,0,A.size()-1,p);
    
}
