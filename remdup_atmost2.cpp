int Solution::removeDuplicates(vector<int> &A) {
    
    int i,count=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(i<n-2 && A[i]==A[i+1]&& A[i+1]==A[i+2]){
            continue;
        }else{
            A[count++]=A[i];
        }
        
    }
    
    
    
    
    
    return count;
}
