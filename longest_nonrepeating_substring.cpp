int Solution::lengthOfLongestSubstring(string A) {
    
    int n=A.length();
    unordered_map<char,int> m;
    for(int i=0;i<n;i++){
        m[A[i]]=-1;
    }
    m[A[0]]=0;
    int prev_idx=0,currlen=1,maxlen=1;
    for(int i=1;i<n;i++){
        prev_idx=m[A[i]];
        if(prev_idx==-1||i-currlen>prev_idx ){
            currlen++;
        }else{
            
            maxlen=max(maxlen,currlen);
            
            currlen=i-prev_idx;
            
        }
        m[A[i]]=i;
        
        
    }
    maxlen=max(currlen,maxlen);
    
    return maxlen;
    
}
