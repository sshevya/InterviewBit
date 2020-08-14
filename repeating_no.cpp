int Solution::repeatedNumber(const vector<int> &A) {
    //HARETORTOISE ALGO FOR DETECTING CYCLE
    //map<int,int> m;
    int n=A.size();
    int slow,fast;
    slow=A[0];
    fast=A[A[0]];
    while(slow!=fast){
        slow=A[slow];
        fast=A[A[fast]];
    }
    fast=0;
    while(slow!=fast){
        slow=A[slow];
        fast=A[fast];
    }
   /* map<int,int>::iterator i;
    for(i=m.begin();i!=m.end();i++){
        
        if(i->second>1){
            return i->first;
        }
    }
   */ 
    
    return slow;
    
}
