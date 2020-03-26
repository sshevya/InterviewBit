vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>> v;
    vector<int> curr_diag;
    curr_diag.push_back(A[0][0]);
    v.push_back(curr_diag);
    if(n==1){
        return v;
    }
    int i,j,k=1;
    while(k<n){
        curr_diag.clear();
        i=0;
        for(j=k;j>=0;j--){
            curr_diag.push_back(A[i][j]);
            i++;
        }
        v.push_back(curr_diag);
        k++;
    }
    k=1;
     while(k<n){
        curr_diag.clear();
        i=n-1;
        for(j=k;j<n;j++){
            curr_diag.push_back(A[j][i]);
            i--;
        }
        v.push_back(curr_diag);
        k++;
    }
    
    
    
    
    
    
    return v;
    
}
