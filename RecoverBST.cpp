
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inorder(TreeNode* A, vector<int> & v){
    if(A==NULL){
        return;
    }
    
    inorder(A->left,v);
    v.push_back(A->val);
    inorder(A->right,v);
    
}
 
vector<int> Solution::recoverTree(TreeNode* A) {
    
    
    vector<int> v,temp,d;
    inorder(A,v);
    
    
    for(int i=0;i<v.size();i++){
        temp.push_back(v[i]);
        
    }
    
    sort(temp.begin(),temp.end());
    
    for(int i=0;i<v.size();i++){
        if(temp[i]!=v[i]){
            d.push_back(temp[i]);
            d.push_back(v[i]);
            break;
        }
    }
    
    
    return d;
    
}
