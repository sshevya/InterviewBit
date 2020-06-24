//to find all subarrays with 0 sum

int findarr(vector<int> a, int sum){
    int n=a.size();
    unordered_map<int,int> prevsum;
    int res=0;
    int currsum=0;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum==sum){
            res++;
        }
        if(prevsum.find(currsum-sum)!=prevsum.end()){
            res+=prevsum[currsum-sum];
        }
        prevsum[currsum]++;
    }
    return res;
}


int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size();
    if(n==0){
        return 0;
    }
    int m=A[0].size();
    if( m==0){
        return 0;
    }
    int left,right,i;
    int ans=0;
    
    for(left=0;left<m;left++){
        vector<int> temp(n,0);
        for(right=left;right<m;right++){
            for(i=0;i<n;i++){
                temp[i]+=A[i][right];
            }
            
            ans+=findarr(temp,0);
        }
    }
    
    return ans;
}
