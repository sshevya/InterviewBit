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

/****
My approach, wrong ans

void next_greater(const vector<int>& A, vector<int>& v){
    
    int n = A.size();
    stack<int> s;
    s.push(n-1);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && A[s.top()]<A[i]){
            s.pop();
        }
        
        if(!s.empty()){
            v[i] = s.top();
        }
        s.push(i);
        
    }
}



int Solution::trap(const vector<int> &A) {
    
    int n = A.size();
    vector<int> v(n,-1);
    int val = 0;
    
    next_greater(A,v);
    
    int i = 0;
    while(i<=n-2 && A[i]<=A[i+1]){
        i++;
    }
    for(;i<n;){
        

        
        if(v[i]==-1){
            i++;
            continue;
        }
        
        if(v[i]-i-1>0){
            
            val += min(A[v[i]], A[i])*(v[i]-i-1);
            //cout<<i<<" "<<val<<" "<<v[i]<<" ";
            int k = i+1;
            while(k<n && k<v[i]){
                val-=A[k];
                k++;
            }
            
            i = v[i];
        }
        else{
            i++;
        }
        
    }
    
    
    
    return val;
}
***/
