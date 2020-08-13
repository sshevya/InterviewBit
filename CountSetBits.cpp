#define mod 1000000007


int Solution::solve(int n) {

      
    // Ignore 0 as all the bits are unset 
    n++; 
  //See GFG
    // To store the powers of 2 
    long long powerOf2 = 2; 
  
    // To store the result, it is initialized 
    // with n/2 because the count of set 
    // least significant bits in the integers 
    // from 1 to n is n/2 
    long long cnt = n / 2; 
  
    // Loop for every bit required to represent n 
    while (powerOf2 <= n) { 
  
        // Total count of pairs of 0s and 1s 
        long long totalPairs = n / powerOf2; 
  
        // totalPairs/2 gives the complete 
        // count of the pairs of 1s 
        // Multiplying it with the current power 
        // of 2 will give the count of 
        // 1s i9n the current bit 
        cnt = (cnt%mod+ ((totalPairs / 2) * powerOf2)%mod)%mod; 
  
        // If the count of pairs was odd then 
        // add the remaining 1s which could 
        // not be groupped together 
        cnt += (totalPairs & 1) ? (n % powerOf2) : 0; 
  
        // Next power of 2 
        powerOf2 <<= 1; 
    } 
  
    // Return the result 
    return cnt%mod;  
}
/***********



DP SOL
#define mod 1000000007


int Solution::solve(int A) {

        int i=0;
        long long ans=0;
        vector<long long> v(A+1,0);

        v[0]=0;
        v[1]=1;
            for(int i=2;i<=A;i++){
                if(i%2==0){
                    v[i]=v[i/2];
                }else{
                    v[i]=1+v[i-1];
                }
                
        }
        for(int i=0;i<=A;i++){
            ans=(ans%mod+v[i]%mod)%mod;

        }
        
 return ans%mod;       
}
*************//
