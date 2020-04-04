void combutil(vector<vector<int>>& v, vector<int>& subset, vector<int> arr, int k, int index){
    if(k==0){
        v.push_back(subset);
    }
    
    if(k<0){
        return ;
    }
    while(index<arr.size()){
        subset.push_back(arr[index]);
        combutil(v,subset,arr,k-1,index+1);
        index++;
        subset.pop_back();
        
    }
    
    
}




vector<vector<int> > Solution::combine(int A, int B) {

    vector<vector<int>> v;
    vector<int> arr,subset;
    for(int i=1;i<=A;i++){
        arr.push_back(i);
    }
    combutil(v,subset,arr,B,0);
   
   return v; 
}
