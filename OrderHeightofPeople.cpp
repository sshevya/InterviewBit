vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n=A.size();
    vector<int> v(n,-1);
    
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++){
        p.push_back(make_pair(A[i],B[i]));
    }
    
    sort(p.begin(),p.end());
    vector<int> temp;
    for(int i=0;i<n;i++){
        temp.push_back(i);
    }
    
    for(int i=0;i<n;i++){
        v[temp[p[i].second]]=p[i].first;
        auto it=temp.begin();
        
        temp.erase(it+p[i].second);
    }
    return v;
}
