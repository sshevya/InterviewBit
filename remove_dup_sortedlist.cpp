/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode* temp=A;
    if(temp->next==NULL){
        return A;
    }
    while(temp->next!=NULL){
        if(temp->val==temp->next->val){
            ListNode* tempnext=temp->next->next;
            
            free(temp->next);
            
            temp->next=tempnext;
            //temp=temp->next;
        }
        else{
            temp=temp->next;
        }
    }
    
    
    
    
    
    
    return A;
    
    
}
