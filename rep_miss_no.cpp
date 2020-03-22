vector<int> Solution::repeatedNumber(const vector<int> &A) {
   // map<int,int> m;
    int n=A.size();
    
    long long int rep,miss;
    
    
    long long int x_y=n*(n+1)/2;
    long long int x2_y2=n*(n+1)*(2*n+1)/6;
    for(int i=0;i<n;i++){
        x_y-=(long long int )A[i]%1000000007;
        x2_y2-=((long long int)A[i]*(long long int)A[i])%1000000007;
    }
    
    long long int xplusy=x2_y2/x_y;
    
    miss=(x_y+x2_y2/x_y)/2;
    rep=miss-x_y;
   
    
    vector<int> v;
    v.push_back(rep);
    v.push_back(miss);
    return v;
}
