int Solution::chordCnt(int A) {
    int n=2*A;
    int dp[n+1]={0};

    dp[0]=1;
    dp[2]=1;
    
    for(int i=4;i<=n;i+=2){
        for(int j=0;j<i-1;j+=2)
        dp[i]+=(dp[j]*dp[i-j-2])%1000000007;
    }
    
    return dp[n]%1000000007;
}
