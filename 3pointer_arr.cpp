int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int n1=A.size();
    int n2=B.size();
    int n3=C.size();
    int i=0,j=0,k=0,mini;
    mini=max(abs(A[i]-B[j]),max(abs(C[k]-A[i]),abs(B[j]-C[k])));
    while(i!=n1 && j!=n2 && k!=n3){
        int cur_min=max(abs(A[i]-B[j]),max(abs(C[k]-A[i]),abs(B[j]-C[k])));
        if(cur_min<mini){
            mini=cur_min;
        }
        int minval=min(A[i],min(B[j],C[k]));
        if(minval==A[i]){
            i+=1;
        }else if(minval==B[j]){
            j+=1;
        }else{
            k+=1;
        }
    }
    return mini;
}
