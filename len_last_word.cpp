int Solution::lengthOfLastWord(const string A) {
    
    int n=A.length();
    int count =0;
    int k=n-1;
    while(A[k]==' '){
        k--;
    }
    for(int i=k;i>=0;i--){
        if(A[i]==' '){
            break;
        }else{
            count++;
        }
    }
    
    
    
    
    
    
    
    
    return count;
}
