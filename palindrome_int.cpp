int Solution::isPalindrome(int A) {
    
    string S=to_string(A);
    int n=S.length();
    int start=0;
    int end=n-1;
    //while start==(n+1)/2 when n=odd
    while(start!=(n+1)/2){
        if(S[start]==S[end]){
            start++;
            end--;
        }else{
            return 0;
        }
    }
    
    
    
    
    
    
    return 1;
}
