
//looks like max/min cost path but is not.calculating max cost path won't give answer
// as it does not guarantee that value does not drop to zero in between


int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();
    int dp[n][m]={0};
    dp[n-1][m-1]=(A[n-1][m-1]>0)?1:1-A[n-1][m-1];
    
    for(int i=m-2;i>=0;i--){
        dp[n-1][i]=max(dp[n-1][i+1]-A[n-1][i],1);
    }
    
    
    for(int i=n-2;i>=0;i--){
        dp[i][m-1]=max(dp[i+1][m-1]-A[i][m-1],1);
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            int minpath=min(dp[i+1][j],dp[i][j+1]);
            dp[i][j]=max(minpath-A[i][j],1);
        }
    }
    
    int minval=dp[0][0];
    
    return minval;
    
}
