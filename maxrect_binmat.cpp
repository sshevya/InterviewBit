int maxar_histogram(vector<int> v){
    stack<int> s;
    int maxarea=0;
    int i=0;
    int tp;
    int currar=0;
    while(i<v.size()){
     
        if(s.empty() || v[s.top()]<v[i]){
            s.push(i++);
        }else{
             tp=s.top();
            s.pop();
            
            currar=v[tp]*(s.empty()?i:i-s.top()-1);
            maxarea=max(currar,maxarea);
        }
        
    }
    
    while(!s.empty()){
          tp=s.top();
            s.pop();
            
            currar=v[tp]*(s.empty()?i:i-s.top()-1);
            maxarea=max(currar,maxarea);
    }
    return maxarea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();
    int maxarea=0,currarea=0;
    maxarea=maxar_histogram(A[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++)
                if(A[i][j])
                A[i][j]=A[i-1][j]+A[i][j];

        
         vector<int> v=A[i];
            currarea=maxar_histogram(v);
            maxarea=max(maxarea,currarea);
    }
    
    
    
    
    
    return maxarea;
}
