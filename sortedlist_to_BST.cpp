/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 TreeNode* sortedRecur(ListNode** A, int n){
     
     if(n<=0){
         return NULL;
     }
     
     TreeNode* left=sortedRecur(A, n/2);
     
    TreeNode* root= new TreeNode((*A)->val);
    
    root->left=left;
    
    *A=(*A)->next;
     root->right=sortedRecur(A,n-n/2-1);
     
     
     
     
     
     return root;
 }
 
 
 
 
 int countnodes(ListNode* A){
     ListNode *temp=A;
     int count=0;
     while(temp){
         count++;
         temp=temp->next;
     }
     return count;
 }
 
 
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
        
        int n=countnodes(A);
    
        return sortedRecur(&A,n);

}
