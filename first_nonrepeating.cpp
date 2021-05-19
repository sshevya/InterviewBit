string Solution::solve(string A) {
    
    int n = A.length();
    string B = "";
    
    queue<char> q;
    q.push(A[0]);
    B+=A[0];
    
    unordered_map<char,int> m;
    m[A[0]]=1;
    
    for(int i=1;i<n;i++){
            m[A[i]]+=1;
            
            if(m[A[i]]==1){
                q.push(A[i]);
            }
        if(m[q.front()]==1){
          //  cout<<"UUU";
            char c = q.front();
            B+=q.front();

        }else{
            
            while(!q.empty() && m[q.front()]>1){
                q.pop();
            }
            
            if(q.empty()){
                B+='#';
            }else{
                char c = q.front();
                B+=c;
            }
            
            
        }
    }
    
    return B;
}
