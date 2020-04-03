void sub(vector<vector<int>> &v, vector<int>& subset, vector<int>& A, int index){
    if(find(v.begin(),v.end(),subset)==v.end()){
    v.push_back(subset);
    }
    for(int i=index;i<A.size();i++){
        subset.push_back(A[i]);
        sub(v,subset,A,i+1);
        subset.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    vector<vector<int>> v;
    vector<int> subset;
    sort(A.begin(),A.end());
    sub(v,subset,A,0);
    return v;


}
