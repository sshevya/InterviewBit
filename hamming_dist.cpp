

int Solution::hammingDistance(const vector<int> &A) {
    
    long long int sum=0;
    int n=A.size();
    for(int i=0;i<32;i++){
        long long int count=0;
        for(int j=0;j<n;j++){
            
            if((A[j]) & (1<<i)){
                count++;
            }
            }
            
            sum+=(2*count*(n-count))%1000000007;
    }
    
    
    return sum%1000000007;
}
