int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    if(B>n){
        B=n;
    }
    vector<vector<int>> dp(B+1,vector(n,0));
    for(int i=0;i<n;i++){
        dp[0][i]=0;
    }
    for(int j=0;j<B+1;j++){
        dp[j][0]=0;
    }
    vector<int> a=A;
    int maxv=INT_MIN;
    int i,j;
    
    for( i=1;i<=B;i++){
         int minv=a[0];
        //   vector<int> curr(n,0);

        for( j=1;j<n;j++){
           dp[i][j]=max(a[j]-minv,dp[i][j-1]);
            /*max(dp[t][i-1],A[i]-A[j]+profit[t-1][j])
            
            max of (max i transactions till day j-1 ) and 
            (max of(profit till jth day with t-1 transactions
            and add diff of curr day and jth day
            to include ith day transaction
            )
            
            A[j] - min(A[j]-dp[i-1][j] for all j less than current j)
            basically max of profit till jth day i-1 transactions plus one more transaction
            curr day - jth day
            
=            */
           minv=min(minv,a[j]-dp[i-1][j]);

            

        }
    }
    
    
    
    
    return dp[B][n-1];
}
