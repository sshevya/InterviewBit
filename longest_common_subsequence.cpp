int Solution::solve(string A, string B) {
    
    int n=A.length();
    int m=B.length();
    int dp[n+1][m+1]={0};
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else{
                if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+max(dp[i][j-1],dp[i-1][j]);
                }
            }
            
        }
    }
    
    
    return dp[n][m];
    
}
