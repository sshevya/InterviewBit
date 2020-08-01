int Solution::bulbs(vector<int> &A) {
    int n=A.size();
    int val=0;
    for(int i=0;i<n;i++){
            if(A[i]==0 && val%2==0){
        
                val++;
            }
            if(A[i]==1 && val%2!=0){
                val++;
            }
    }
    
    return val;
    
}
