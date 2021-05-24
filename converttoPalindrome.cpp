int Solution::solve(string A) {
    
    int n = A.length();
    int i = 0;
    int j = n-1;
    int p,q;
    int count =0;
    int ans = 0;
    while(i<j){
        if(A[i]==A[j]){
            i++;
            j--;
        }else{
           
           break;
            
        }
    }
    if(i>=j){
        return 1;
    }
    
    
    p=i+1;
    q=j;
    while(p<q){
        if(A[p]==A[q]){
            p++;
            q--;
        }else{
            
            break;
            
        }
    }
    if(p>=q){
        return 1;
    }
    
    p=i;
    q=j-1;
    while(p<q){
         if(A[p]==A[q]){
            p++;
            q--;
        }else{
            
            return 0;
        }
    }
    
    
    
    
    return 1;
    
}
