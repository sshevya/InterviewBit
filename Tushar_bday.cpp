vector<int> Solution::solve(int A, vector<int> &B) {
    
    int n=B.size();
    int min_val=B[0];
    vector<pair<int,int>> v;
    int min_idx=0;
    v.push_back(make_pair(0,B[0]));
    for(int i=1;i<n;i++){
        if(B[i]<min_val){
            v.push_back(make_pair(i,B[i]));
            min_val=B[i];
            min_idx=i;
        }
    }
    
    int max_length=v.size();
    int val=A;
    int i=0;
    vector<int> ans;
    while(i<max_length){
        if(val>=v[i].second && (1+(val-v[i].second)/min_val)==val/min_val){
            val-=v[i].second;
            ans.push_back(v[i].first);
        }else{
            i++;
        }
    }
    
    
    
    
    
    return ans;
    
}
