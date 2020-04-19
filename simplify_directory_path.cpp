string Solution::simplifyPath(string A) {
    
    int n=A.length();
    stack<string> st;
    
    string res="";
    
    for(int i=0;i<n;i++){
        
        string s="";
        if(A[i]=='/'){
            continue;
        }
        
        else if(A[i]=='.'){
            if(i+1<n && A[i+1]=='.'){
                if(!st.empty()){
                    st.pop();
                    
                }
                i++;
            }
        }
        else{
            while(i<n && A[i]!='/'){
                s.push_back(A[i]);
                i++;
            }
            
            st.push(s);
        }
        
    
    }
    
    
    while(!st.empty()){

       res.insert(0,'/'+st.top()); 
       
       
       st.pop();
    }
    if(res==""){
        res.push_back('/');
    }
   

    return res;
    
    
    
}
