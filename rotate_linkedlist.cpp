/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int size(ListNode* head){
    ListNode* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    
    int n=size(A);
    if(B>n){
        B=B%n;
    }
    int k=n-B;
    
    
    ListNode* curr_node=A;
    ListNode* new_end;
    int i=1;
    while(i<k && curr_node!=NULL){
        curr_node=curr_node->next;
        
        i++;
    }
     
   
   ListNode* kth_node=curr_node;
   while(curr_node->next!=NULL){
       curr_node=curr_node->next;
   }
    curr_node->next=A;
    A=kth_node->next;
    kth_node->next=NULL;
    
    
    
    
    return A;
}
