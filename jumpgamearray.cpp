int Solution::canJump(vector<int> &A) {
    int n=A.size();
    int dp[n]={0};
    dp[0]=1;
    int maxjump=A[0];
    for(int i=0;i<n;i++){
        if(dp[i]>0 && A[i]>0){
            maxjump=A[i];
        
        for(int j=0;j<=maxjump;j++){
            if(i+j<n){
                dp[i+j]=1;
            }
        }
        }
    }  
        
        
        return dp[n-1];
}
