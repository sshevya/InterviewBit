int Solution::isInterleave(string A, string B, string C) {
    
    int  n=A.length();
    int m=B.length();
    int k=C.length();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            
            else if(i==0){
                if(B[j-1]==C[j-1])
                    dp[i][j]=dp[i][j-1];
            }
            else if(j==0){
                if(A[i-1]==C[i-1])
                    dp[i][j]=dp[i-1][j];
            }
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1]){
                dp[i][j]=dp[i-1][j];
            }
            else if(A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1]){
                dp[i][j]=dp[i][j-1];
            }
            else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]){
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }
        }
    }
    
    return dp[n][m];
    
    
}
