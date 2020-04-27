int Solution::maxcoin(vector<int> &A) {
    int n=A.size();
    int dp[n][n]={0};
    
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            
            dp[i][j]=max(A[i]+min(dp[i+2][j],dp[i+1][j-1]),A[j]+min(dp[i+1][j-1],dp[i][j-2]));
            
            
            
        }
    }
    
    
    
    
    
    return dp[0][n-1];
    
}
