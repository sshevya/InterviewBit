int Solution::removeElement(vector<int> &A, int B) {

    int n=A.size();
    int i,count=0;
    for(int i=0;i<n;i++){
        if(A[i]==B){
            continue;
        }else{
            A[count++]=A[i];
        }
        
    }
    
    return count;
}
