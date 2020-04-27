int Solution::numDistinct(string A, string B) {
    int n=A.length();
    int m=B.length();
    if(n<m){
        return 0;
    }
    int dp[n+1][m+1]={0};
   
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    
     for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(B[j-1]!=A[i-1]){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
            
        }
    }
    
    
    
    
    
    return dp[n][m];
}
