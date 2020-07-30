int Solution::maxProfit(const vector<int> &A) {
    
    
    int n=A.size();
    if(n<2){
        return 0;
    }
    vector<vector<int>> dp(3,vector(n,0));
    int i,j;
    for( j=1;j<=2;j++){
    int minv=A[0];
    for(i=1;i<n;i++){
        dp[j][i]=max(dp[j][i-1],A[i]-minv);
        minv=min(minv,A[i]-dp[j-1][i]);
    }
    
    }
    
    
    
    
    
    
    
    
    
    return dp[2][n-1];
    
}
