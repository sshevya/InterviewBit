bool isAdj(string A, string B){
    int count=0;
    int n=A.length();
    for(int i=0;i<n;i++){
        if(A[i]!=B[i]){
            count++;
        }
        if(count>1){
            return false;
        }
    }
    
    return true;
}


int Solution::solve(string A, string B, vector<string> &C) {
             /*   if(find(C.begin(),C.end(),word)==C.end()){
                        return 0;
                }*/
    int n=C.size();
    vector<bool> v(n,false);
    queue<pair<string,int>> q;
    q.push(make_pair(A,1));
    
    while(!q.empty()){
        string s=q.front().first;
        int dis=q.front().second;
        q.pop();
        if(s==B){
            return dis; 
        }
        if(isAdj(s,B)){
            return dis+1;
            
        }
        
        
        for(int i=0;i<n;i++){
            if(!v[i] && isAdj(s,C[i])){
                q.push(make_pair(C[i],dis+1));
                v[i]=true;
            }
        }
    }
    
    
    
    return -1;
}
