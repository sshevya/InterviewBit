/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* rec(ListNode* a, ListNode* b){
    
    ListNode* result=NULL;
    
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
     
    if(a->val<=b->val){
        result=a;
        result->next=rec(a->next,b);
    }else{
        result=b;
        result->next=rec(a,b->next);
    }
     return result;
 }

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int k=A.size()-1;
    while(k!=0){
        int i=0;
        int j=k;
        
        while(i<j){
            A[i]=rec(A[i],A[j]);
            i++;
            j--;
            
            
            if(i>=j){
                k=j;
            }
        }
        
    
    }
    
    
    
    
    
    return A[0];
    
    
    
}
