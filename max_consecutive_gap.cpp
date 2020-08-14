int Solution::maximumGap(const vector<int> &arr) {
    int n=arr.size();
    if(n<2){
        return 0;
    }
    int maxv=INT_MIN;
    int minv=INT_MAX;
    for(int i=0;i<n;i++){
        maxv=max(maxv,arr[i]);
        minv=min(minv,arr[i]);
    }
    
    vector<int> max_arr(n-1,INT_MIN);
    vector<int> min_arr(n-1,INT_MAX);
    
    float gap=(float)(maxv-minv)/(float)(n-1);
    for(int i=0;i<n;i++){
        if(arr[i]==minv || arr[i]==maxv){
            continue;
        }
        
        int index=(float)(floor(arr[i]-minv)/gap);
        
        if(max_arr[index]==INT_MIN){
            max_arr[index]=arr[i];
        }else{
            max_arr[index]=max(max_arr[index],arr[i]);
        }
        if(min_arr[index]==INT_MAX){
            min_arr[index]=arr[i];
        }else{
            min_arr[index]=min(min_arr[index],arr[i]);
        }
        
        
    }
    
    int prev_val=minv;
    int max_gap=INT_MIN;
    for(int i=0;i<n-1;i++){
        if(min_arr[i]==INT_MAX){
            continue;
        }
        
        max_gap=max(max_gap,min_arr[i]-prev_val);
        prev_val=max_arr[i];
    }
    max_gap=max(max_gap,maxv-prev_val);

    return max_gap;
}



