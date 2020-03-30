int Solution::trailingZeroes(int A) {
    
    int count5=0;
    
    for(int i=5;i<=A;i*=5){
        count5+=A/i;
    }
    
    
    
    
    return count5;
}
