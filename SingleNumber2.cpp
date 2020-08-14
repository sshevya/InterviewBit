int Solution::singleNumber(const vector<int> &A) {
    
    int n=A.size();
    int ones=0;
    int twos=0;
    int common_bits=0;
    for(int i=0;i<n;i++){
        twos=twos|(ones&A[i]);  //the numbers that are in ones and A[i] both will be in twos now
        ones=ones^A[i]; 
        
        common_bits=~(ones&twos);
        
        ones&=common_bits;
        twos&=common_bits;
        
        
        
        
    }
    
    return ones;
    
}
