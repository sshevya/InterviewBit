void permutebc(vector<vector<int>>& v, vector<int>& A, int l, int r){
    if(l==r){
        v.push_back(A);
    }
    
    for(int i=l;i<=r;i++){
        swap(A[l],A[i]);
        permutebc(v,A,l+1,r);
        swap(A[l],A[i]);
    }
    
}


vector<vector<int> > Solution::permute(vector<int> &A) {
    
    int n=A.size();
    vector<vector<int>> v;
    permutebc(v,A,0,n-1);
    
    return v;
}
