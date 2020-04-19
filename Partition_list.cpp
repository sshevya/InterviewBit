/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    
    
    ListNode *s1=NULL,*e1=NULL;
    ListNode *s2=NULL,*e2=NULL;
    
    ListNode *temp=A;
    
    while(temp!=NULL){
        if(temp->val<B){
            if(s1==NULL){
                e1=new ListNode(temp->val);
                s1=e1;
            }else{
                e1->next=new ListNode(temp->val);
                e1=e1->next;
            }
        }else{
            if(s2==NULL){
                e2=new ListNode(temp->val);
                s2=e2;
            }else{
                e2->next=new ListNode(temp->val);
                e2=e2->next;
            }
            
        }
        
        temp=temp->next;
       
        
    }
    
    if(s1==NULL){
        return s2;
    }
    e1->next=s2;    
    
    
    return s1;
    
}
