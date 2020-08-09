#define MOD 1000000007
vector<vector<long long>> choose(int n, int k){
    vector<vector<long long>> nck(n+1,vector<long long>(k+1,0));
    
    for(int i=0;i<=n;i++){
        nck[i][0]=1;
        nck[i][i]=1;
    }
    for(int i=0;i<=n;i++){
    for(int j=0;j<=min(i,k);j++){
        if(j==0 ||j==i)
            nck[i][j]=1;
        else
        nck[i][j]=(nck[i-1][j-1]%MOD+nck[i-1][j]%MOD)%MOD;
        }
    }

    return nck;  

}

int getleft(int n){
    if(n==1){
        return 0;
    }
    
 int h=log2(n);
   /* int copy=n;
    while(copy>1){
        h++;
        copy/=2;
    }
     */  
    int val=(1<<h);
    int last=n-((1<<h)-1);
      //  cout<<last;

    if(last>=(val/2)){
        return (1<<h)-1;
    }
        return (1<<h)-1-((val/2)-last);
    
}

int Solution::solve(int A) {
    
    vector<vector<long long>> nck=choose(A,A);
        vector<long long> dp(A+1,0);
        
    
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=A;i++){
            
            int left=getleft(i);
          //  cout<<left;
            dp[i]=(nck[i-1][left]*dp[left])%MOD*dp[i-left-1]%MOD;
           // cout<<nck[i-1][left];
        }
    
    return dp[A];
}
