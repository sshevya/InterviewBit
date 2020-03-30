int fact(int n){
    int fact[n+1];
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=(i*fact[i-1])%1000003;
    }
    return fact[n];
}

int findsmaller(string A, int l, int r){
    int count=0;
    for(int i=l+1;i<r;i++){
        if(A[l]>A[i]){
            ++count;
        }
    }
    return count;
}
int Solution::findRank(string A) {
    int n=A.length();
    //int countright=0;
     int fact_i=fact(n);
    int rank=1;
    for(int i=0;i<n;i++){
       
        int countright=findsmaller(A,i,n);
       // cout<<countright<<" ";
        rank+=(countright*fact(n-i-1))%1000003;
        //cout<<fact_i<<" ";
    }
    
    
    
    
    return rank%1000003;
}
