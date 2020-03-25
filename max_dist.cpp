int Solution::maximumGap(const vector<int> &A) {
    int n=A.size();
    if(n==1){
        return 0;
    }
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
   
    int diff=0;
    
    int min_so_far=v[0].second;
    
    for(int k=1;k<n;k++){
       diff=max(diff,v[k].second-min_so_far); 
       min_so_far=min(min_so_far,v[k].second);
        
    }
 return diff;   
}
