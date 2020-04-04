int Solution::strStr(const string A, const string B) {
    
    int n=B.length();
    int m=A.length();
    
    if(n==0 || m==0|| m<n){
        return -1;
    }
    int j,k;
    for(int i=0;i<m;i++){
        if(A[i]==B[0]){
            j=0; k=i;
            while(A[k]==B[j] && k<m){
                k++;
                j++;
            }
            
            if(j==n){
                return i;
            }
        }
    }
    
    
    
    return -1;
}
