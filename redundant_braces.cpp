int Solution::braces(string A) {
    
    int n=A.length();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(isalpha(A[i])){
            continue;
        }
        else{
            if(A[i]==')'){
                char a=st.top();
                if(a=='('){
                    return 1;
                }
                if(!st.empty()){
                    while(st.top()!='('){
                        st.pop();
                        
                    }
                    st.pop();
                    
                }
            }else{
                st.push(A[i]);
            }
        }
    }
    
    return 0;
}
