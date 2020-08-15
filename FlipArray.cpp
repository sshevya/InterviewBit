vector<int> Solution::flip(string a) {
    
    int n=a.length();
    vector<int> A;
        vector<int> v;
//Change 1 to -1 and 0 to 1 to apply max sum subarray if all elements 1 no changes can be made
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            count++;
            A.push_back(-1);
        }else{
            A.push_back(1);
        }
    }
    if(count==n){
        return v;
    }
    
    
    //find max sum contigous array and store indices
    int curr_max=A[0];
    int max_so_far=A[0];
    int start=0,s=0;
    int end=0;
    
    for(int i=1;i<n;i++){
    
        if(curr_max+A[i]<A[i]){
            s=i;
            curr_max=A[i];
        }else{
            curr_max+=A[i];
        }
        
        
        if(max_so_far<curr_max){
            max_so_far=curr_max;
            start=s;
            end=i;
        }
        
    }/*
    //if need to print all subarrays with this sum 
    
    //check for all indices before n if possible
    unordered_map<int, int> m;
    int e;
    s=-1;
    curr_max=0;
    for(int i=0;i<start;i++){
        curr_max+=A[i];
        
        
        if(curr_max==max_so_far){
            s=0;
            e=i;
            break;
        }
        
        if(m.find(curr_max-max_so_far)!=m.end()){
            s=m[curr_max-max_so_far]+1;
            e=i;
        }
        
        m[curr_max]=i;

        
    }
    
    
    if(s!=-1  && s<start){
        start=s;
        end=e;
}
    */
    v.push_back(start+1);
    v.push_back(end+1);
    
    
    
    
    
    
    
    return v;
    
}

