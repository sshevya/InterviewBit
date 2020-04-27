//const vector,so to sort first copy in another vector
//Also update j & k after assigning max val to maxlen


int Solution::solve(const vector<int> &arr) {
    
    int n=arr.size();
    if(n==1){
        return 1;
    }
    int dp[n][n]={0};
    int maxlen=2;
    int A[n]={0};
    for(int i=0;i<n;i++){
        A[i]=arr[i];
    }
    sort(A,A+n);
    for(int i=0;i<n;i++){
        dp[i][n-1]=2;
    }
    //Everytime choose ith elt as middle element and look for AP with 3 terms see gfg
    //dp[j][i] shows length of AP with jth and ith term
    for(int i=n-2;i>=1;i--){
        int j=i-1;
        int k=i+1;
        
        while(j>=0 && k<n){
            if(A[j]+A[k]>2*A[i]){
                //if greater this means there is no AP with jth and ith as its last terms
                //so we first assign 2
               dp[j][i]=2;
                j--;
            }else if(A[j]+A[k]<2*A[i]){
                k++;
            }else{
                dp[j][i]=dp[i][k]+1;

                maxlen=max(maxlen,dp[j][i]);
                                j--;
                k++;
            }
        }
    }
    
    
    
    
    return maxlen;
    
}
