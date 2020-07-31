vector<vector<vector<bool>>> dp;
vector<int> original;
vector<int> res;
int total_size;
bool isPossible(int index, int curr_size, int curr_sum){
    
    if(curr_size==0){
        return (curr_sum==0);
    }
    if(index>=total_size){
        return false;
    }
    
    
    if(dp[index][curr_size][curr_sum]==false){
        return false;
    }
    
    if(curr_sum>=original[index]){
        
        res.push_back(original[index]);
        
        if(isPossible(index+1,curr_size-1,curr_sum-original[index])){
            return true;
        }
        res.pop_back();
    }
    
    if(isPossible(index+1,curr_size,curr_sum)){
        return true;
    }
    
    return dp[index][curr_size][curr_sum]=false;
    //return false;
}



vector<vector<int> > Solution::avgset(vector<int> &A) {
    sort(A.begin(),A.end());
    total_size=A.size();
    dp.clear();
    res.clear();
    original.clear();
    original=A;
    int sum=0;
    for(int i=0;i<total_size;i++){
        sum+=A[i];
    }
    
    dp.resize(total_size,vector<vector<bool>>(total_size,vector<bool>(sum+1,true)));
    
    for(int i=1;i<total_size;i++){
        if((sum*i)%total_size!=0){
            continue;
        }
        
        int sum_set1=(sum*i)/total_size;
        
        if(isPossible(0,i,sum_set1)){
            
            vector<int>res1=res;
            vector<int> res2;
            int ptr1=0;
            int ptr2=0;
            while(ptr1<A.size() || ptr2< res.size()){
                if(ptr2<res.size() && res[ptr2]==A[ptr1]){
                    ptr2++;
                    ptr1++;
                    continue;
                }
                
                res2.push_back(A[ptr1]);
                ptr1++;
            }
            vector<vector<int>> ans;
            ans.push_back(res1);
            ans.push_back(res2);
            return ans;
            
        }
        
    }
        vector<vector<int>> ans;
        
        return ans;
    
    
    
}
