int Solution::maxProfit(const vector<int> &A) {
    
    int n=A.size();
    int minv=INT_MAX;
    int profit;
    for(int i=0;i<n;i++){
        profit=max(profit,A[i]-minv);
        minv=min(A[i],minv);
    }
    
    
    
    return profit;
    
}
