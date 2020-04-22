/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //allot value to left node first in preorder and right first if postorder given
 //use & with vector for faster computation
int searchindex(vector<int>& v,int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(v[i]==val){
            return i;
        }
    }
} 
 
 
TreeNode* rec(vector<int>& in, vector<int>& pre, int start, int end, int& pindex){
    
    if(start>end){
        return NULL;
    }
   TreeNode* root=new TreeNode(pre[pindex]) ;
   pindex++;
   
   if(start==end){
       return root;
   }
   
   
   
   
   int index=searchindex(in,start,end,root->val);
   //allot left node first otherwise different answer;

   root->left=rec(in,pre,start, index-1, pindex);
         root->right=rec(in,pre,index+1,end,pindex);

    return root;
    
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int p=0;
    return rec(B,A,0,B.size()-1,p);
}
