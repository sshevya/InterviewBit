/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int size(ListNode* head){
    ListNode*temp=head;
    int count =0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    return count;
} 

 
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    int n=size(A);
    ListNode* temp=A;
    if(B>=n){
        A=A->next;
        return A;
    }
    int k=n-B+1;
    int i=1;
    while(i<k-1){
        temp=temp->next;
        i++;
    }
    ListNode* tempnext=temp->next->next;
    free(temp->next);
    temp->next=tempnext;
    return A;
    
}
