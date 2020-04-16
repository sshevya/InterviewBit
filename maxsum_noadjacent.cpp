


int Solution::adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    
    int incl_sum=max(A[0][0],A[1][0]);
    int excl_sum=0, excl_new;

    for(int i=1;i<n;i++){
        
        excl_new=max(excl_sum,incl_sum);
        
        incl_sum=excl_sum+max(A[0][i],A[1][i]);
        
        excl_sum=excl_new;
        
        
    }
    
    
return max(excl_sum,incl_sum);    
}


