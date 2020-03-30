#include<bits/stdc++.h>
void reverseStr(string& str) 
{ 
    int n = str.length(); 

    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
}

int Solution::reverse(int A) {
    if(A<0 && A>INT_MIN){
      
    string s=to_string(-1*A);  //can't use inbuilt function cause of same name
    reverseStr(s);
    
    long long int a=stol(s);
     if(a>2147483648 || a< -2147483648){
        return 0;
    }
    return -1*a;
    }else if(A>=0 && A<INT_MAX) {
       
    string s=to_string(A);
    reverseStr(s);
    
    long long int a=stol(s);
    if(a>2147483648 || a< -2147483648){
        return 0;
    }
    return a;
    }
    
    
    
  return 0;  
}
