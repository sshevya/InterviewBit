


int Solution::adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    /**
    DP Sol
    
    int dp[n]={0};
    dp[0]=max(A[0][0],A[1][0]);

    dp[1]=max(dp[0],max(A[0][1],A[1][1]));
    dp[2]=max(dp[0]+max(A[0][2],A[1][2]),dp[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-2]+max(A[0][i],A[1][i]),dp[i-1]);
    }
    
    return dp[n-1];

**/
    int incl_sum=max(A[0][0],A[1][0]);
    int excl_sum=0, excl_new;

    for(int i=1;i<n;i++){
        
        excl_new=max(excl_sum,incl_sum);
        
        incl_sum=excl_sum+max(A[0][i],A[1][i]);
        
        excl_sum=excl_new;
        
        
    }
    
    
return max(excl_sum,incl_sum);    
}


