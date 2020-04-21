int Solution::colorful(int A) {
    
    vector<int> v;
    unordered_map<int,int> m;
    while(A!=0){
        int a=A%10;
        v.push_back(a);
        A=A/10;
    }
    
    for(int i=0;i<v.size();i++){
        int val=1;
        for(int j=i;j<v.size();j++){
            val*=v[j];
            
            if(m.find(val)!=m.end()){
                return 0;
            }
            m[val]=1;
        }
    }
    
    
    return 1;
}
