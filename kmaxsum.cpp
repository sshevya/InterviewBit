vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    int n=A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int val=A[n-1]+B[n-1];
    
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> m;
    vector<int> v;
    
    pq.push(make_pair(val,make_pair(n-1,n-1)));
    m.insert(make_pair(n-1,n-1));
    
    while(v.size()!=n){
        auto temp=pq.top();
        pq.pop();
        v.push_back(temp.first);
        
        int i=temp.second.first;
        int j=temp.second.second;
        
        val=A[i-1]+B[j];
        if(m.find(make_pair(i-1,j))==m.end()){
            pq.push(make_pair(val,make_pair(i-1,j)));
            m.insert(make_pair(i-1,j));
        }
        
         val=A[i]+B[j-1];
        if(m.find(make_pair(i,j-1))==m.end()){
            pq.push(make_pair(val,make_pair(i,j-1)));
            m.insert(make_pair(i,j-1));
        }
        
        
        
        
    }
    
    return v;
    
}
