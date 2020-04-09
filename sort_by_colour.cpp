void Solution::sortColors(vector<int> &A) {
    
    int n=A.size();
    int i=0;
    
    for(int p=0;p<n;p++){
        if(A[p]<1){
            swap(A[p],A[i]);
            i++;
        }
    }
    int k=0;
     for(int p=0;p<n;p++){
        if(A[p]<2){
            swap(A[p],A[k]);
            k++;
        }
    }
    
}
