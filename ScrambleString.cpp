


int Solution::isScramble(const string A, const string B) {
    
    int n=A.length();
    int p=B.length();
    if(n!=p){
        return 0;
    }
    
    
    // string copyA=A;
    //string copyB=B;
    if(A==B){
        return true;
    }
    
    vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(n,vector<bool>(n,0)));
    /*
    Starting at i in A and j in b substring of length 0 is scrambled
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j][0]=(A[i]==B[j]);
        }
    }
    /*
    Starting at index i in A and j in B a substring of length k is scrambled if for any p 
    starting at i substring of length p is scrambled with substring of length p starting at j in B 
    and substring of length k-p-1 starting at i+p+1 in A is scrambled with substring starting at j+p+1 in B
    OR
     starting at i substring of length p is scrambled with substring of length p starting at j+k-p in B 
    and substring of length k-p-1 starting at i+p+1 in A is scrambled with substring starting at j in B
    
    
    */
    
    for(int k=1;k<n;k++){
        for(int i=0;i<n-k;i++){
            for(int j=0;j<n-k;j++){
                dp[i][j][k]=0;
                
                for(int p=0;p<k;p++){
                    if((dp[i][j][p] && dp[i+p+1][j+p+1][k-p-1]) || (dp[i][j+k-p][p] && dp[i+p+1][j][k-p-1])){
                        dp[i][j][k]=1;
                        break;
                    }
                }
                }
        }
    }
     return dp[0][0][n-1];
}
