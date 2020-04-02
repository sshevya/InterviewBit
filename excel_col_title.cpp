string Solution::convertToTitle(int A) {
    
    string s="";
    if(A<=26){
        s+=char(A+'A'-1);
        return s;
    }
    
    while(A>0){
        int rem=A%26;
        if(rem==0){
            s+='Z';
            A=A/26-1;
        }else{
        s+=char(A%26+'A'-1);
                A=A/26;
        }

    }
    
    
    
    
    reverse(s.begin(),s.end());
    
    return s;
    
}
