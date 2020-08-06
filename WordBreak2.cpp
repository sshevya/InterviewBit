/**Sol by recursion see DP***/

vector<string> rec(string A, vector<string> &B, unordered_map<string, vector<string>>& m){
    
    if(m.count(A)){
        return m[A];
    }
    int n=A.length();
    vector<string> result;
    for(int i=1;i<=n;i++){
        string pre=A.substr(0,i);
        string suf=A.substr(i);
        
        if(find(B.begin(),B.end(),pre)!=B.end()){
            if(suf.empty()){
                result.push_back(pre);
            }
            
            for(auto s: rec(suf,B,m))
            
            result.push_back(pre+" "+s);

        }
    }
    
    m[A]=result;
    return result;
}







vector<string> Solution::wordBreak(string A, vector<string> &B) {
    
    unordered_map<string, vector<string>> m;
    return rec(A,B,m);

}
