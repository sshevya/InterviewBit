
/*********
int computeFactorials(int& k, int n){
   if(n==1){
       return 0;
   }
   
   n--;
    int num=n;

   
   while(k>=num && n>1){
       num=num*(n-1);
       n--;
   }
    
    int index=k/num;
    k=k%num;
    
    return index;
    
}
string Solution::getPermutation(int A, int B) {
    
    set<int> s;
    for(int i=1;i<=A;i++){
        s.insert(i);
    }
   set<int>::iterator itr;
   itr=s.begin();
   string news="";
   B=B-1;
   for(int i=0;i<A;i++){
       int ind=computeFactorials(B,A-i);
       
       advance(itr,ind);
       
       news+=(to_string(*itr));
       s.erase(itr);
       itr=s.begin();
   }
    
    return news;
}

***/
