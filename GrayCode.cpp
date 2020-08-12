void backtrack(vector<string>& v, int in, int A){
    if(in>A){
        return;
    }
   // vector<string> temp=v;
//    reverse(temp.begin(),temp.end());
  //  cout<<temp[1];
    for(int i=v.size()-1;i>=0;i--){
       // reverse(temp[i].begin(),temp[i].end());
        string s="1"+v[i];
        v[i]="0"+v[i];
        v.push_back(s);
    }
    
    backtrack(v,in+1,A);
    
}




vector<int> Solution::grayCode(int A) {

    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    
    
    backtrack(v,2,A);
    vector<int> res;
    for(int i=0;i<v.size();i++){
        int a=stoi(v[i],0,2);
        
        res.push_back(a);
    }
    
    return res;
    
}
