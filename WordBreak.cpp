
int Solution::wordBreak(string A, vector<string> &B) {
        
    int n=A.length();
    vector<int> dp(n+1,0);
    unordered_set<string> m;
    for(int i=0;i<B.size();i++){
        m.insert(B[i]);
    }
    
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            
            if(dp[j]){
                if(m.find(A.substr(j,i-j))!=m.end()){
                    dp[i]=1;
                    break;
                }
            }
            
        }
    }
    return dp[n];
    
}
/****



int Solution::wordBreak(string A, vector<string> &B) {
    
    int n=A.length();
    vector<int> dp(n+1,0);
    unordered_set<string> m;
    for(int i=0;i<B.size();i++){
        m.insert(B[i]);
    }
    vector<int> matched;
    matched.push_back(-1);
    for(int i=0;i<n;i++){
        int msize=matched.size();
        int flag =0;
        for(int j=msize-1;j>=0;j--){
            string s=A.substr(matched[j]+1,i-matched[j]);
            if(m.find(s)!=m.end()){
                flag=1;
                break;
            }
        }
        if(flag){
            dp[i]=1;
            matched.push_back(i);
        }
        
        
        
        
    }
    
    
    return dp[n-1];
    
}

***/
