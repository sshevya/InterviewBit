int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

    int n1=A.size();
    int n2=B.size();
    int n3=C.size();
    int diff;
    
    int i=0,j=0,k=0;
    diff=abs(max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k])));
    while(i!=n1 && j!=n2 && k!=n3){
        int curr_diff=abs(max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k])));
        if(curr_diff<diff){
            diff=curr_diff;
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
    
    
    return diff;
}
