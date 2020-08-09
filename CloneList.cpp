/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    RandomListNode* l=A;
    
    map<RandomListNode*, RandomListNode*> m;
    RandomListNode* newl=new RandomListNode(A->label);

    RandomListNode* head=newl;
    m[l]=head;
    l=l->next;
    while(l){
        RandomListNode* temp=new RandomListNode(l->label);
        m[l]=temp;
        head->next=temp;
        head=temp;
        
        l=l->next;
        
    }
    
    
    l=A;
    head=newl;
    
    while(l!=NULL){
        if(l->random)
        head->random=m[l->random];
        else
        head->random=NULL;
        
        head=head->next;
        l=l->next;
    }
    
    
    return newl;
    
}
