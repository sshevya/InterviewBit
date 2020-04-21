vector<int> Solution::lszero(vector<int> &A) {
  /* boundary case imp,when sum=0*/  
    int n=A.size();
    unordered_map<int,int> m;
    int sum=0, maxlen=0;
    int index;
    m[0]=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0){
            index=0;
            maxlen=i+1;
        }
        if (m.find(sum) != m.end()){
    
            int currlen=i-m[sum];
            
            if(maxlen<currlen){
                maxlen=currlen;
                index=m[sum]+1;
            }
        }
         else{
             m[sum]=i;
         }
    }
    
    vector<int> v;
    
    for(int i=index;i<maxlen+index;i++){
        v.push_back(A[i]);
    }
    
    return v;
}
