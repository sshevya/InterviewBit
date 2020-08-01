void createFibonacci(vector<int>& v, int K){
        v.push_back(0);
        v.push_back(1);
        int i=2;
        int val=0;
        while(val<=K){
            val=v[i-2]+v[i-1];
            i++;
            v.push_back(val);
        }

    
}


int Solution::fibsum(int A) {

    vector<int> fib;
    createFibonacci(fib,A);
    
    int i=fib.size()-1;
    int k=0;
    while(A!=0){
        
        k+=A/fib[i];
        
        A=A%fib[i];
        i--;
    }
    
    return k;
}
