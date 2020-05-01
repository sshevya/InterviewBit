int Solution::solve(const vector<int> &A) {
    int n=A.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
    }
    unordered_map<int,int> dp[2];
    for(int j=-sum;j<=sum;j++){
        dp[0][j]=INT_MAX;
    }
    dp[0][0]=0;
    bool flag=1;
    for(int i=1;i<=n;i++){
        for(int j=-1*sum;j<sum;j++){
           dp[flag][j]=INT_MAX;
            if(j-A[i-1]<=sum && j-A[i-1]>=-1*sum){
                    dp[flag][j]=dp[flag^1][j-A[i-1]];
            }
            if(j+A[i-1]<=sum && j+A[i-1]>=-1*sum && dp[flag^1][j+A[i-1]]!=INT_MAX){
                dp[flag][j]=min(dp[flag][j],dp[flag^1][j+A[i-1]]+1);
            }
           
        }
        flag=flag^1;
    }
     for (int i = 0; i <= sum; i++) { 
        if (dp[flag ^ 1][i] != INT_MAX) 
            return dp[flag ^ 1][i]; 
    } 
    
    
    
}
