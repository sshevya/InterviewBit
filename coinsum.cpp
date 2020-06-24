int Solution::coinchange2(vector<int> &A, int B) {
    
    int n=A.size();
    int res=0;
    int sum[B+1]={0};
     sum[0]=1;
    
    for(int i=0;i<n;i++){
        for(int j=A[i];j<=B;j++){
            sum[j]=(sum[j]+sum[j-A[i]])%1000007;
           // sum[i]=(x+y)%1000007;
            
        }
    }
    
    return sum[B];
    
}
