int Solution::solve(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    for(int i=0;i<n-1;i++){
        if(A[i]==A[i+1]){
            continue;
        }
        if(n-1-i==A[i]){
            return 1;
        }
    }
    if(A[n-1]==0){
        return 1;
    }
    return -1;
}
