bool isPalindrome(string s){
    int n=s.length();
    int i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int Solution::minCut(string A) {
    int n=A.length();
    vector<int> dp(n+1,0);
if(isPalindrome(A)){
    return 0;
}
    dp[0]=-1;
    dp[1]=0;
    bool check=false;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            
        string s=A.substr(j,i-j);
        if(isPalindrome(s)){
            check=true;
            if(dp[i]){
                dp[i]=min(dp[j]+1,dp[i]);
            }else{
                dp[i]=dp[j]+1;
            }
        }
        }
        if(!check){
            dp[i]=i-1;
        }
        
    }
    if(dp[n]==0){
        return n-1;
    }else{
        return dp[n];
    }
    
}
