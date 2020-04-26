/* linear solution possible
int Solution::jump(vector<int> &A) {
    
    int n=A.size();
    int dp[n]={0};
    int maxjump=A[0];
    int minn=min(n-1,A[0]);
    for(int i=1;i<=minn;i++){
        dp[i]=1;
    }
    
    for(int i=1;i<n;i++){
        if(dp[i]>0 && A[i]>0){
            maxjump=min(n-1,A[i]);
        
            for(int j=0;j<=maxjump;j++){
                if(i+j<n){
                    if(dp[i+j]!=0){
                    dp[i+j]=min(dp[i+j],1+dp[i]);
                    }else{
                        dp[i+j]=1+dp[i];
                    }
                }
            }
        }
    }
    
    if(dp[n-1]==0 && n!=1){
        return -1;
    }
    
   return dp[n-1]; 
}
*/



int Solution::jump(vector<int> &A) {
    
    int n=A.size();
    int steps=A[0];
    int maxreach=A[0];
    int jump=1;
    if(n==1){
        return 0;
    }
    
    for(int i=1;i<n-1;i++){
    
       maxreach=max(maxreach,i+A[i]);
       steps--;
       if(steps<0){
           return -1;
       }
       if(steps==0){
           jump++;
          
           steps=maxreach-i;
       }
       
       
       
       
    }
    if(maxreach>=n-1){
        return jump;
    }
  
   return -1; 
}
