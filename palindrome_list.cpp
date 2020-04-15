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
 
 
int Solution::lPalin(ListNode* A) {
    
    int n=size(A);
    ListNode* temp=A;
    int m=n/2;
    int i=0;
    vector<int> v;
    while(i!=m){
        int a=temp->val;
        v.push_back(a);
        temp=temp->next;
        i++;
        
    }
    if(n%2!=0){
        temp=temp->next;
    }
    
    while(temp!=NULL){
        int a=v.back();
        if(a!=temp->val){
            return 0;
        }
        temp=temp->next;
        v.pop_back();
        
    }
    
    return 1;
}
