vector<int> Solution::findPerm(const string A, int B) {
    
    vector<int> v;
    vector<int> s;
    int n = A.length();
    
    
    for(int i=1;i<=n;i++){
        if(A[i-1]=='I'){
            s.push_back(i);
            
            while(!s.empty()){
                int b = s.back();
                s.pop_back();
                v.push_back(b);
            }
            
        }else{
            s.push_back(i);
        }
    }
    s.push_back(n+1);
     while(!s.empty()){
                int b = s.back();
                s.pop_back();
                v.push_back(b);
            }
            
    return v;
    
    
}
