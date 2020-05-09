int Solution::numSetBits(unsigned int A) {
    int c = 0;
    /*while(A)  //Simple O(log n) approach
    {
        if (A & 1)
            ++c;
        A >>= 1;
    }*/
    while(A!=0) //Brian Kernighan’s Algorithm: iterates only over set bits
    {
        A &= A-1;
        ++c;
    }
    return c;    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
