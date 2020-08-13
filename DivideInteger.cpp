int Solution::divide(int A, int B) {
    
    int sign=((A<0) ^ (B<0) )?-1:1;
    
    
    unsigned long long temp=0;
    unsigned long long divisor=abs((long long )B);
    unsigned long long dividend=abs((long long)A);
    
    long long quotient=0;
    
    for(int i=31;i>=0;i--){
        if(temp+(divisor<<i)<=dividend){
            temp+=divisor<<i;
            quotient|=1LL<<i;
        }
    }
    
    
    return (sign*quotient>=INT_MAX || sign*quotient <INT_MIN)?INT_MAX:sign*quotient;
    
}
