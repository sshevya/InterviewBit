string Solution::minWindow(string A, string B) {
    
    unordered_map<char,int> str; //stroes freq of char in B
    unordered_map<char,int> pat;
    
    for(int i=0;i<B.length();i++){
        if(pat.find(B[i])!=pat.end()){
        pat[B[i]]+=1;
        }
        else{
            pat[B[i]]=1;
        }
    }
    for(int i=0;i<A.length();i++){
    
        str[A[i]]=0;
        
                

    }
    
    int start_idx=-1,count=0,minlen=INT_MAX,j=0;
    for(int i=0;i<A.length();i++){
        str[A[i]]+=1;
      // cout<<pat[A[i]]<<str[A[i]];
        if(pat.find(A[i])!=pat.end() && str[A[i]]<=pat[A[i]]){
            count++;
        }
       //cout<<count;
    
        if(count==B.length()){
            
            while(str[A[j]]>pat[A[j]] || pat.find(A[j])==pat.end()){
                if(str[A[j]]>pat[A[j]]){
                    str[A[j]]--;
                }
                j++;
            }
            
        
        int len=i-j+1;
        if(minlen>len){
            minlen=len;
            start_idx=j;
        }
          // cout<<start_idx<<" "<<minlen<<" "<<len;

        
        }
        
    }
    if(start_idx==-1){
       string s="";
        return s;
    }
    string s="";
    for(int i=start_idx;i<start_idx+minlen;i++){
        s+=A[i];
    }
    
    return s;
    
}
