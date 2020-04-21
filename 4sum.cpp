vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {

    vector<vector<int>> ans;
    unordered_map<int,vector<pair<int,int>>> m;
    int sum;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-1;i++){
        
        for(int j=i+1;j<A.size();j++){
            
            sum=A[i]+A[j];
            
            if(m.find(B-sum)!=m.end()){
                vector<pair<int,int>> av=m[B-sum];
                for(int k=0;k<av.size();k++){
                vector<int> v;
                
                auto num=m[B-sum][k];
                int a=num.first;
                int b=num.second;
                if(a!=i && a!=j && b!=i && b!=j){
                v.push_back(A[a]);
                v.push_back(A[b]);
                v.push_back(A[i]);
                v.push_back(A[j]);
                sort(v.begin(),v.end());
                if(find(ans.begin(),ans.end(),v)==ans.end()){
                ans.push_back(v);
                }
                }
                }
            }
                m[sum].push_back(make_pair(i,j));
            
        }
    
    }
    stable_sort(ans.begin(),ans.end());
    
    return ans;
}
