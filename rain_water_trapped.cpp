int max_(int a,int b){
    if(a>b){
        return a;
    }
        return b;
    
}

int min_(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}

int Solution::trap(const vector<int> &A) {
    
    int n=A.size();
    int val=0;
    vector<int> lmax(n,0);
    vector<int> rmax(n,0);
    int max=A[0];
    lmax[0]=A[0];
    for(int i=1;i<n;i++){
        lmax[i]=max_(lmax[i-1],A[i]);
    }
    rmax[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=max_(rmax[i+1],A[i]);
    }
    for(int i=0;i<n;i++){
        val+=min_(lmax[i],rmax[i])-A[i];
    }
    
    
    
    return val;
}
