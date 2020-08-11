string Solution::addBinary(string A, string B) {
    
    int n=A.length();
    int m=B.length();
    
    int i=n-1;
    int j=m-1;
    string res="";
    int s=0;

    while(i>=0 || j>=0 || s==1){
        
        s+=(i>=0?A[i]-'0':0);
        s+=(j>=0?B[j]-'0':0);
        
        
        res=char(s%2+'0')+res;
        
        s/=2;
        
        
        i--;
        j--;
    }
    /*
    while(i>=0){
        
        s+=(A[i]-'0');
        res=char(s%2+'0')+res;
        s/=2;
        i--;
    }
    while(j>=0){
        
        s+=(B[i]-'0');
        res=char(s%2+'0')+res;
        s/=2;
        j--;
    }
    
    */
    return res;
    
    
}
