/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //see second solution in comment below,more efficient
 void rec(TreeNode* A,vector<vector<int>>& v, vector<int>& sol){
    if(A==NULL){
        return;
    }
    bool lefttoright=true;
    stack<TreeNode*> currlevel,nextlevel;
    currlevel.push(A);
    while((!currlevel.empty())){
        TreeNode* curr=currlevel.top();
        currlevel.pop();
        if(curr){
            //cout<<curr->val<<" ";
            sol.push_back(curr->val);
            if(lefttoright){
                if(curr->left){
                    nextlevel.push(curr->left);
                }
                if(curr->right){
                    nextlevel.push(curr->right);
                }
            }else{
        
                if(curr->right){
                    nextlevel.push(curr->right);
                }
                    if(curr->left){
                    nextlevel.push(curr->left);
                }
           }
        
        }
        if(currlevel.empty()){
            lefttoright=!lefttoright;
            v.push_back(sol);
            sol.clear();
            swap(currlevel,nextlevel);
        
        }
        
    }
    
    
 }
 
 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> v;
    vector<int> sol;
    if(A==NULL){
        return v;
    }
    
    rec(A,v,sol);
    return v;
    
}

/*
void zig(TreeNode* A, vector<vector<int> >& sol, bool left, int level){
    if(A == NULL){
        return;
    }
    
    if(sol.size() < level){
        vector<int> temp;
        sol.push_back(temp);
    }
    
    if(left){
        sol[level-1].push_back(A->val);
    }
    else{
        sol[level-1].insert(sol[level-1].begin(), A->val);
    }
    
    zig(A->left, sol, !left, level+1);
    zig(A->right, sol, !left, level+1);
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
   
    vector<vector<int> > sol;
    
    zig(A, sol, true, 1);
    
    return sol;
}
*/
