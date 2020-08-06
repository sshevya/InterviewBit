int Solution::isMatch(const string A, const string B) {

    int n=A.length();
    int m=B.length();
    
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
    
    dp[0][0]=1;
    
    /*for(int i=1;i<n+1;i++){
        dp[i][0]=0;
    }*/
    
    for(int i=1;i<m+1;i++){
        if(B[i-1]=='*'){
            dp[0][i]=dp[0][i-1];
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(B[j-1]==A[i-1] || B[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }else if(B[j-1]=='*'){
                dp[i][j]=dp[i-1][j]|| dp[i][j-1];
            }else{
                dp[i][j]=0;
            }
        }
    }
    
    return dp[n][m];
}
