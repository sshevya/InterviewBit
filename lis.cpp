int Solution::lis(const vector<int> &A) {
    
    int n=A.size();
    int lis[n];
    int maxl=0;
    for(int i=0;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>A[j] && lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
                
            }
            maxl=max(maxl,lis[i]);
        }
    }
    return maxl;
}
