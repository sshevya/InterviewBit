/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void level(TreeNode* A, int B, int h, int& ans){
     if(A==NULL){
         return ;
     }
     
     if(A->val == B){
         ans=h;
         return;
     }
     
     level(A->left, B, h+1, ans);
     level(A->right, B, h+1, ans); 
     
 }
/**
Find level at which node is present 
push all nodes of that level whose parents are different 


**/
 
 void find(TreeNode* A,TreeNode* parent, int level, int h,  int B, vector<int>& v){
     if(A==NULL){
         return ;
     }
     
     if(level==h & A->val!=B){
         
        if(parent->left==A){
            if(parent->right!=NULL){
                if(parent->right->val!=B){
                    v.push_back(A->val);
                }
            }else{
                v.push_back(A->val);
            }
        }
        
        
        if(parent->right==A){
            if(parent->left!=NULL){
                if(parent->left->val!=B){
                    v.push_back(A->val);
                }
            }else{
                v.push_back(A->val);
            }
        }
        
     }
     
     find(A->left, A, level+1, h, B, v);
     find(A->right, A, level+1, h, B, v);
     
     
 }
 
 

     
 
 
 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    
    
    vector<int> v;
    if(A==NULL || A->val==B){
        return v;
    }
    
    int h=1;
    level(A,B,1,h);
    find(A,NULL,1,h,B, v);
    
    
    
    
    return v;
    
}
