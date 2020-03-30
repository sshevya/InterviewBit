int Solution::titleToNumber(string A) {
    
    int n=A.length();
    int res=0;
    int val=1;
    for(int i=0;i<n;i++){
     res*=26;
     res+=(A[i]-'A')*val+1;
     
    }
    
    
    
    
   return res; 
    
}
