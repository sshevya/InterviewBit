int comp(int a, int b){
    string c="";
    c+=to_string(a)+to_string(b);
    string d="";
    d+=to_string(b)+to_string(a);
    return c.compare(d) > 0 ? 1: 0; 
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> v=A;
    int n=A.size();
    sort(v.begin(),v.end(),comp);
    string s="";
    s+=to_string(v[0]);
    int k=1;
    while(v[k]==0){
    
        k++;
    }
    for(int i=k;i<n;i++){
        
          s+=to_string(v[i]);
    }
    
    return s;
}
