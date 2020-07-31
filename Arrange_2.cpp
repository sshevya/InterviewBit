int Solution::arrange(string A, int B) {
    
   int n = A.length();
    int dp[n][B];   // dp[i][j] = minimum val of accommodation 
                    // till i'th index of the string 
                    // using j+1 number of stables. 
                    // Final ans will be in dp[n-1][B-1]

    memset(dp, 0, sizeof dp);

    if(n<B) return -1;
    else if(n==B) return 0;

    // filling first column 
    int wt=0, bk=0;
    for(int i=0; i<n; i++){
        if(A[i]=='B') bk++;
        else wt++;
        dp[i][0]=bk*wt;
    }

    for(int j=1; j<B; j++){
        for(int i=0; i<n; i++){
            wt=0, bk=0;
            dp[i][j]=INT_MAX;
            for(int k=i; k>=0; k--){
                if(A[k]=='B') bk++;
                else wt++;
                dp[i][j] = min(dp[i][j], bk*wt +   ((k-1>=0)?dp[k-1][j-1]:0)   );
            }
        }
    }

    return dp[n-1][B-1];
}
