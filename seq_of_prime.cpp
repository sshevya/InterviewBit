vector<int> Solution::solve(int A, int B, int C, int D) {
    
    vector<int> ans;
    if(D==0){
        return ans;
    }
    set<int> v;

    v.insert(A);
    v.insert(B);
    v.insert(C);
    while(!v.empty()){
        int curr=*v.begin();
        v.erase(v.begin());
        ans.push_back(curr);
        if(ans.size()==D){
            break;
        }
        v.insert(curr*A);
        v.insert(curr*B);
        v.insert(curr*C);
        
    }
    return ans;
    
    
}
