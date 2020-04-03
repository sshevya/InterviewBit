int Solution::maxProfit(const vector<int> &A) {
    
    int n=A.size();
    long long int buy=A[0];
    long long int profit=0;
    for(int i=1;i<n;i++){
        if(A[i]>A[i-1]){
            profit+=A[i]-A[i-1];
        }
    }
    
    
    
    
    
  return profit;  
    
}
