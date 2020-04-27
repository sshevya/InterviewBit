// linear solution,see dp approach too


bool ispalindrome(string A){
    int i=0,j=A.length()-1;
    while(i<j){
        if(A[i]!=A[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int Solution::anytwo(string A) {
    
    int n=A.length();
    unordered_map<char,int> m;
  
    
    for(int i=0;i<n;i++){
        if(m.find(A[i])!=m.end()){
            m[A[i]]+=1;
        }else{
            m[A[i]]=1;
        }
        if(m[A[i]]>2){
            return 1;
        }
    }
    string s="";
    for(int i=0;i<n;i++){
        if(m[A[i]]>1){
            s+=A[i];
        }
    }
    int k=s.length();
    if(ispalindrome(s)){
        if(k%2!=0){
            if(s[k/2]==s[k/2-1]){
                return true;
            }
        }
        return false;
    }
    return  true;
}
