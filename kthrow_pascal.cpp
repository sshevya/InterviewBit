vector<int> Solution::getRow(int A) {
   
    vector<int> prev,curr;
    vector<vector<int>> v;
  
    prev.push_back(1);
    v.push_back(prev);
    if(A==0){
        return prev;
    }
    prev.push_back(1);
     v.push_back(prev);
    if(A==1){
        return prev;
    }
    for(int i=2;i<=A;i++){
        curr.clear();
        curr.push_back(1);
        for(int j=1;j<prev.size();j++){
            curr.push_back(prev[j]+prev[j-1]);
        }
        curr.push_back(1);
        prev=curr;
        v.push_back(curr);
    }
    
    
    
    return v[A];
    



}
