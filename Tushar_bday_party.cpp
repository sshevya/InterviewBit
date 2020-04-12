#define MOD 1000000007;
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int n=B.size();
    
    int max_el=*max_element(A.begin(),A.end());

    vector<vector<int>> dp(max_el + 1, vector<int>(B.size() + 1, 0));    
    
     for (int i = 1; i <= max_el; i++) {
        dp[i][0] = MOD;
    }
    for(int i=1;i<=max_el;i++){
        for(int j=1;j<=B.size();j++){
            if(i-B[j-1]>=0){
               dp[i][j]=min(dp[i][j-1],dp[i-B[j-1]][j]+C[j-1]); 
            }else{
                dp[i][j]=dp[i][j-1];
            }
            
        }
    }
    
    int result=0;
    for(const auto &i:A){
        result+=dp[i][B.size()];
    
    }
    
    
    
    
    
    return result;
    
}
