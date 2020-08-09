string Solution::fractionToDecimal(int a, int b) {
    
     if (a == 0)
        return "0";
    int64_t A = a, B = b;
    string s = "";
    
    if (A < 0 ^ B < 0)      //Brilliant
        s += '-';
    unordered_map<int64_t, int64_t> m;
    if(B==1 || B==-1){
        s+=to_string(A/B);
        return s;
    }
      A=abs(a);
    B=abs(b);
 
    int64_t Integer=A/B;
    int64_t val;
    if(A%B==0){
        s+=to_string(Integer);

        return s;

    }
    else{
        s+=to_string(Integer);
        s+='.';
        val=A%B;
    }
    bool check=false;

    for(;val;val%=B){
        if(m.find(val)!=m.end()){
            
          s.insert(m[val],1,'(');
            s+=')';
            break; 
        }
        
        m[val]=s.size();

        val=10*val;

        s+=to_string(abs(val/B));
        
        
        
    }
    
    
    
    
    
    
    return s;
    
}
