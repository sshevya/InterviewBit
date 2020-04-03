int minl(int a, int b, int c){
    int smallest=a;   
    if(b<smallest){
        smallest=b;
    }
    if(c<smallest){
        smallest=c;
    }
    return smallest;
}


int Solution::minDistance(string A, string B) {
    
    int n=A.length();
    int m=B.length();
    int dp[n+1][m+1]={0};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            
            if(i==0){
                dp[i][j]=j;
            }else if(j==0){
                dp[i][j]=i;
            }else if(A[i-1]==A[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else {
                dp[i][j]=1+minl(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
            }
            
            
            
        }
    }
    
    
    
    
    
    
    
    return dp[n][m];
    
}
