int Solution::numSetBits(unsigned int A) {
    
    /****Subtracting one from binary number flips all digits after rightmost 1 including 1, 
     * so & of n, n-1 will unset rightmost set bit, no of times this happeens is number of 1*****/
    //Brian Kernighan;'s algo
    int count =0;
    while(A!=0){
        A=A&(A-1);
        count++;
    }
    

    
    return count;
    
    
}
