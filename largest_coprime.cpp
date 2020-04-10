int gcd(int x, int y){
    
    int dividend=x>y?x:y;
    int divisor=x>y?y:x;
    
    while(divisor!=0){
        int rem=dividend%divisor;
        dividend=divisor;
        divisor=rem;
    }
    
    return dividend;
}


int Solution::cpFact(int A, int B) {

    while(gcd(A,B)!=1){
        A=A/gcd(A,B);
    }

return A;
}
