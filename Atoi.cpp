int Solution::atoi(const string A) {
    
    
    int n=A.length();
    long long a=0;
    int i=0;
    while(i<n && (A[i]==' ' )){
        i++;
    }
    
    if(i==n){
        return 0;
    }    
    bool ch=false;
    if(A[i]=='-' || A[i]=='+'){
        if(A[i]=='-')
        ch=true;
        
        i++;
    }
    
    while(i<n &&(A[i]!=' ' && A[i]-'0'>=0 && A[i]-'0'<=9)){
        if(a>INT_MAX/10 || a==INT_MAX/10 && A[i]-'0'>7){
            if(ch)
            return INT_MIN;
            return INT_MAX;
        }
        a=a*10+(A[i]-'0');
        
    i++;
        }
    
    if(ch){
        a=-1*a;
    }
    
    
    
    
    
    
    return a;
}
