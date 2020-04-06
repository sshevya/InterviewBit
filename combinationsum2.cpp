void backtrack(vector<vector<int>>& v, vector<int>& subset, vector<int>& arr, int target, int index){
    if(target==0 && find(v.begin(),v.end(),subset)==v.end()){
        v.push_back(subset);
        return ;
    }
    if(target<0){
        return ;
    }
    
    while(index<arr.size() && target >=arr[index]){
        subset.push_back(arr[index]);
        backtrack(v,subset,arr,target-arr[index],index+1);
        index++;
        subset.pop_back();
    }
    
    
    
}





vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    
    vector<vector<int>> v;
    vector<int> subset;
    sort(A.begin(),A.end());
    backtrack(v,subset,A,B,0);
    
    
    
    return v;
    
}
