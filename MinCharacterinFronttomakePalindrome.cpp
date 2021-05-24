void LPS(vector<int>& lps, string A, int n){
    
    int i = 1;
    int len = 0;
    
    while(i<n){
        if(A[i]==A[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    
    
    
    
}

int Solution::solve(string A) {
    
    int n=A.length();
    vector<int> lps(2*n+1,0);
    
    
    
    string s = A ;
    reverse(s.begin(),s.end());
    s=A+"$"+s;
    LPS(lps, s, 2*n+1);
    
    int count = n - lps.back();
    
    return count;
}
