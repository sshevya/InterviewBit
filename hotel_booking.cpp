bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    int count =0,max_c=0;
    vector<pair<int,int>> m;
    for(int i=0;i<arrive.size();i++){
        m.push_back(make_pair(arrive[i],1));

          m.push_back(make_pair(depart[i],0));  
    }
    
    sort(m.begin(),m.end());
    for(int i=0;i<m.size();i++){
        if(m[i].second==1){
            count++;
            max_c=max(max_c,count);
        }else{
            count--;
        }
    }
    
    if(max_c<=K){
        return 1;
    }
    
    return 0;
}
