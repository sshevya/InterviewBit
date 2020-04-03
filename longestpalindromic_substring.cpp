string Solution::longestPalindrome(string A) {
    
    int n=A.size();
    
    int start=0,maxlen=1;
    
   
    for(int i=1;i<n;i++){
        int low=i-1;
        int high=i;
         //for even length palindromic substring
        while(low>=0 && high <n && A[low]==A[high]){
            if(high-low+1>maxlen){
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
         //for odd length palindromic substring
        low=i-1;
        high=i+1;
        
        while(low>=0 && high<n && A[low]==A[high]){
            if(high-low+1>maxlen){
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
            
        }
        
    }
    
    
    

    string s="";
    for(int i=start;i<start+maxlen;i++){
        s+=A[i];
    }
    
    
    
    return s;
}
