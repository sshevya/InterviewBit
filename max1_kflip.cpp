vector<int> Solution::maxone(vector<int> &A, int B) {
    //similar to longest subarray containing B zeroes
    int n=A.size();
    int l=0;
    int maxlen=0;
    int count0=0,start=0;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            count0++;
        }
        
        while(count0>B){
            if(A[l]==0){
                count0--;
            }
            l++;
        }
        if(maxlen<i-l+1){
            start=l;
            maxlen=i-l+1;
        }
    }
    vector<int> v;
    for(int i=start;i<=start+maxlen-1;i++){
        v.push_back(i);
    }
    
    
    
    
    return v;
    
}
