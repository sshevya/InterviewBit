bool isprime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}



vector<int> Solution::primesum(int A) {
    
    vector<int> v;
    for(int i=2;i<A-1;i++){
        if(isprime(i) && isprime(A-i)){
            v.push_back(i);
            v.push_back(A-i);
            return v;
        }
    }
    
    
    
}
