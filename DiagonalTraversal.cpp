/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *//****This does not give preorder hence wrong
vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int>>m;
    vector<int> v;
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
        q.push(make_pair(top->left,h+1));
        
        
        if(top->right)
        q.push(make_pair(top->right,h));

}
    map<int,vector<int>>::iterator i;
    for(i=m.begin();i!=m.end();i++){
        for(int j=0;j<(i->second).size();j++)
        v.push_back((i->second)[j]);
        
    }
    return v;
}
***/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/***** First Solution using above concept***/

void rec(TreeNode* A, map<int, vector<int>>& m, int h){
    
    
    if(A==NULL){
        return;
    }
    m[h].push_back(A->val);
    
    rec(A->left, m, h+1);
    rec(A->right, m, h);
    
}
 /*Can't do this using BFS like in vertical order traversal because we have to do it according */
 /* to preorder traversal*/
 
vector<int> Solution::solve(TreeNode* A) {
    
      map<int,vector<int>>m;
    vector<int> v;
    if(A==NULL){
        return v;
    }
    
    rec(A,m,0);
    map<int,vector<int>>::iterator i;
    for(i=m.begin();i!=m.end();i++){
       vector<int> temp = i->second;
        v.insert(v.end(), temp.begin(), temp.end());
        
    }
    return v;
}







/***** Second Solution******/
vector<int> Solution::solve(TreeNode* root) {
   vector<int> v;
    // base case 
    if (root == NULL) 
        return v; 
  
    // inbuilt queue of Treenode 
    queue<TreeNode*> q; 
  
    // push root 
    q.push(root); 
  
    // push delimiter 
    q.push(NULL); 
  
    while (!q.empty()) { 
        TreeNode* temp = q.front(); 
        q.pop(); 
  
        // if current is delimiter then insert another 
        // for next diagonal and cout nextline 
        if (temp == NULL) { 
  
            // if queue is empty return 
            if (q.empty()) 
                return v; 
  
            // output nextline 

            // push delimiter again 
            q.push(NULL); 
        } 
        else { 
            while (temp) { 
                v.push_back(temp->val); 
  
                // if left child is present  
                // push into queue 
                if (temp->left) 
                    q.push(temp->left); 
  
                // current equals to right child 
                temp = temp->right; 
            } 
        } 
    } 
    return v;
}
