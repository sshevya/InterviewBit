
int Solution::solve(int A, int B) {

   long long int dp[A][B]={0};
   if(B>9*A || B==0){
       return 0;
   }
   
   for(int i=0;i<B;i++){
       if(i<=8){
           dp[0][i]=1;  //if one digit number sum can be max 9
       }else{
           dp[0][i]=0;
       }
    
   }
   for(int i=0;i<A;i++){
       dp[i][0]=1; //if sum 1, only 1 number possible regardless of number of digits
   }
   
   
   for(int i=1;i<A;i++){
       for(int j=1;j<B;j++){
         
           int k=0;
           if(j>=9){
               k=j-9;
           }
           for(;k<=j;k++){
               dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
           }
       }
   }
   
    
    return dp[A-1][B-1];
}

