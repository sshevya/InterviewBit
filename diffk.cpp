int Solution::diffPossible(const vector<int> &A, int B) {
    
    unordered_map<int,int> m;
    for(int i=0;i<A.size();i++){
        
        if(m.find(B+A[i])!=m.end()){
            return 1;
        }
        if(m.find(A[i]-B)!=m.end()){
            return 1;
        }
        m[A[i]]=1;
    }
    
    
    return 0;
    
}
