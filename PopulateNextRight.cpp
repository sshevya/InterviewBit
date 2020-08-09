 
 /**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 TreeLinkNode* nextRight(TreeLinkNode* curr){
     
     
     TreeLinkNode* currNext=curr->next;
     while(currNext){
         if(currNext->left){
             return currNext->left;
         }
         else if(currNext->right){
             return currNext->right;
         }
         currNext=currNext->next;
     }
     return NULL;
 }
 
 
 
void Solution::connect(TreeLinkNode* A) {
    if(!A)
    return;
    A->next=NULL;
    while(A){
        TreeLinkNode* temp=A;
        
        while(temp){
            if(temp->left){
                if(temp->right)
                temp->left->next=temp->right;
                else
                temp->left->next=nextRight(temp);
            }
            
            
            if(temp->right){
                
                temp->right->next=nextRight(temp);
            }

            temp=temp->next;
        }
    
        if (A->left)
            A = A->left;
        else if (A->right)
            A = A->right;
        else
            A = nextRight(A);
    }

    
    
    
    
}

 
 
 /************** TLE
void Solution::connect(TreeLinkNode* A) {
    
    
queue<pair<TreeLinkNode*,int>> q;
q.push(make_pair(A,0));
A->next=NULL;
while(!q.empty()){
    TreeLinkNode* temp=q.front().first;
    int l=q.front().second;
    q.pop();
    if(!q.empty()){
        TreeLinkNode* temp2=q.front().first;
    int l2=q.front().second;
        while(l==l2){
            temp->next=temp2;
            q.pop();
            if(q.empty()){
                break;
            }
            temp2=q.front().first;
            l2=q.front().second;
        }
            if(q.empty())
            temp2->next=NULL;
    }else{
        temp->next=NULL;
    }
    if(A->left)
    q.push(make_pair(A->left,l+1));
    if(A->right)
    q.push(make_pair(A->right,l+1));
    
}
    
    
return;
}*************/
