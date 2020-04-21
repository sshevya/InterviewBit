vector<int> Solution::equal(vector<int> &A) {
    
    unordered_map<int, pair<int,int>> m;
    vector<int> v,ans;
    int sum;
    
    for(int i=0;i<A.size()-1;i++){
        for(int j=i+1;j<A.size();j++){
            sum=A[i]+A[j];
            if(m.find(sum)!=m.end()){
                int a=m[sum].first;
                int b=m[sum].second;
                v.clear();
                if(a!=i && a!=j && b!=i && b!=j){
                v.push_back(a);
                v.push_back(b);
                v.push_back(i);
                v.push_back(j);
                }
            // this portion important for getting smallest in lexicographic order
            //since answer has to be in order of index we don't have to sort
                if (ans.size() == 0)
                        ans = v;
                    else
                    {
                        for (auto t = 0; t<ans.size(); ++t)
                        {
                            if (ans[t] < v[t])
                                break;
                            if (ans[t] > v[t])
                            {
                                ans.clear();
                                ans = v;
                                break;
                            }
                        }
                    }
            }
            else{
                m[sum]=make_pair(i,j);
            }
        }
    }
    
    
    
    
    
    
    return ans;
    
}
