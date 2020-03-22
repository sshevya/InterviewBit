int Solution::maxSubArray(const vector<int> &A) {
    
    int n=A.size();
    int max_till_now=A[0];
    int curr_max=A[0];
    
    for(int i=1;i<n;i++){
        curr_max=max(A[i],curr_max+A[i]);
        max_till_now=max(curr_max,max_till_now);
    }
    
    
    
    
    
    return max_till_now;
}
