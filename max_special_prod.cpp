int Solution::maxSpecialProduct(vector<int> &A) {
    
    int n=A.size();
    vector<long long int> left(n,0), right(n,0);
    stack<long long int> sleft,sright;
    
    for(int i=0;i<n;i++){
        
        while(!sleft.empty() && A[i]>=A[sleft.top()]){
            sleft.pop();
        }    
        if(!sleft.empty()){
            left[i]=sleft.top();
        }
        
        sleft.push(i);
        
        
    } 
    
    for(int i=n-1;i>=0;i--){
        
        while(!sright.empty() && A[i]>=A[sright.top()]){
            sright.pop();
        }    
        if(!sright.empty()){
            right[i]=sright.top();
        }
        
        
        sright.push(i);
        
        
    } 
    
    long long int ans = -1;
    for(int i=0;i<n;i++){
      //don't use mod during multiplication
        ans = max(ans, (left[i]*right[i]));
    }
    
    return ans%1000000007;
}
