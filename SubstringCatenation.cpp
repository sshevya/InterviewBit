vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    
    int n=B.size();
    int l1=A.length();
    int l2=B[0].length();
    vector<int> v;
    if(l2>l1){
        return v;
    }
    map<string,int> m;
    int count=0;
    for(int i=0;i<n;i++){
        m[B[i]]+=1;
    }
    string s;
    
    int i,j;
    int sm=n*l2;
    for(i=0;i<l1-sm+1;i++){
            map<string,int> res(m);

        count=n;    
        for(j=i;j<i+sm;j+=l2){
            
        string s=A.substr(j,l2);
        if(m.find(s)==m.end() || res[s]==0){
            break;
        }else{
            res[s]--;
            count--;
        }

    } if(count==0){
                v.push_back(i);
            }
        
    }
    
    return v;
    
}
