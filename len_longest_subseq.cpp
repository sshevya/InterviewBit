

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n=A.size();
    int lis[n],lds[n];
  
    for(int i=0;i<n;i++){
        lis[i]=1;
        lds[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j] && lis[i]< lis[j]+1){
                lis[i]=lis[j]+1;
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(A[i]>A[j] && lds[i]< lds[j]+1){
                lds[i]=lds[j]+1;
                
            }
        }
    }
    int maxl=0;
    
    for(int i=0;i<n;i++){
        if(maxl<lis[i]+lds[i]-1){
        maxl=lis[i]+lds[i]-1;
    }
    }
    return maxl;
}
