string removespaces(string A){
    int n=A.length();
    string s="";
    for(int i=0;i<n;i++){
        if((A[i]>='A' && A[i] <= 'Z')){
            s+=A[i]+32;
        }else if((A[i]>='a' && A[i]<='z' )|| (A[i]>='0' && A[i]<='9')){
            s+=A[i];
        }else{
            continue;
        }
    }
    return s;
}


int Solution::isPalindrome(string A) {
    
    string s=removespaces(A);
    int l=s.length();
    int i=0,j=l-1;
    int m=l/2;
    while(i<l/2){ 
        if(s[i]==s[j] ){
            i++;
            j--;
        }
        else if(s[i]!=s[j] ){
            return 0;
        }
    }
    
    
    
    return 1;
    
}
