vector<int> Solution::wave(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    int m=n;
    if(n%2!=0){
        m=n-1;
    }
    for(int i=0;i<m;i+=2){
        swap(A[i],A[i+1]);
    }
    return A;
}
