int nCr(int n, int k) 
{ 
    int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (int i = 1; i <= n; i++) 
    { 
        
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 

int Solution::solve(vector<int> &A, int B, int C) {
    
    int n=A.size(),d2;
    int count=0,num=0;
    string s=to_string(C);
    int len=s.length();// no of digits in C
    if(B>len || n==0){
        return 0;
    }else if(B<len){
        if (A[0] == 0 && B != 1) 
            return (n - 1) * pow(n, B - 1); 
        else
            return pow(n, B); 
    }else{
        int dp[B+1];
        
        int low[11]={0};
        for(int i=0;i<n;i++){
            low[A[i]+1]=1;
        }
        for(int i=1;i<=10;i++){
            low[i]+=low[i-1];
        }
        
        bool flag = true; 
        dp[0] = 0; 
        for (int i = 1; i <= B; i++) { 
            d2 = low[int(s[i - 1])-'0']; 
            dp[i] = dp[i - 1] * n; 
  
            // For first index we can't use 0 
            if (i == 1 && A[0] == 0 && B != 1) 
                d2 = d2 - 1; 
  
            // Whether (i-1) digit of generated number 
            // can be equal to (i - 1) digit of C 
            if (flag) 
                dp[i] += d2; 
  
            // Is digit[i - 1] present in A ? 
            flag = (flag & (low[int(s[i - 1])-'0' + 1] 
                            == low[int(s[i - 1])-'0'] + 1)); 
        } 
        return dp[B]; 
        
        
        
    }
   
    
    
    
    
}
