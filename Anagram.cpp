vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    vector<vector<int>> v;
    unordered_map<string,vector<int>> m;
    
    for(int i=0;i<A.size();i++){
        string s=A[i];
        sort(s.begin(),s.end());
        
        m[s].push_back(i+1);
    }
    
    
    for(auto i : m){
        vector<int> k=i.second;
        //if(k.size()>1){ //if only anagramic lists are to be returned  check size
            v.push_back(k);
        
    }
    
    
    
    
    
    return v;
    
}
