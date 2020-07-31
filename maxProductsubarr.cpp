int Solution::maxProduct(const vector<int> &A) {
    
    int n=A.size();
    
    int maxval=A[0];
    int minval=A[0];
    int res=maxval;
    for(int i=1;i<n;i++){
        if(A[i]<0){
            swap(minval, maxval);
        }
        
        maxval=max(maxval*A[i], A[i]);
        minval=min(minval*A[i],A[i]);
        
        res=max(res,maxval);
    }
    
    
    
    
    return res;
    
}
