/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /******************This does not take care of preorder criteria,for that wee need dfs
 void rec(TreeNode* A, int level, map<int,vector<int> >&m){
     if(A==NULL){
         return;
     }
     m[level].push_back(A->val);
     
     rec(A->left, level-1, m);
     
     rec(A->right,level+1,m);
     
     
 }
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int,vector<int>>m;
    rec(A,0,m);
    vector<vector<int>> v;
    map<int,vector<int>>::iterator i;
    for(i=m.begin();i!=m.end();i++){
        v.push_back(i->second);
        
    }
    return v;
}
****************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 ///BFS sol to take care of preorder cond
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int,vector<int>>m;
    vector<vector<int>> v;
    if(A==NULL){
        return v;
    }
     queue<pair<TreeNode*,int>> q;
     q.push(make_pair(A,0));
     while(!q.empty()){
     
        TreeNode* top=q.front().first;
        int h=q.front().second;
        q.pop();
        m[h].push_back(top->val);
        if(top->left)
        q.push(make_pair(top->left,h-1));
        if(top->right)
        q.push(make_pair(top->right,h+1));

}
    map<int,vector<int>>::iterator i;
    for(i=m.begin();i!=m.end();i++){
        v.push_back(i->second);
        
    }
    return v;
}
