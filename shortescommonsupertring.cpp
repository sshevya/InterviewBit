int findoverlapping(string str1, string str2, string &str){
    
    int len1=str1.length();
    int len2=str2.length();
    int max=INT_MIN;
    
    for(int i=1;i<=min(len1,len2);i++){
        if(str1.compare(len1-i,i,str2,0,i)==0){
            if(max<i){
                max=i;
                str=str1+str2.substr(i);
            }
        }
    }
    for(int i=1;i<=min(len1,len2);i++){
        if(str1.compare(0,i,str2,len2-i,i)==0){
            if(max<=i){
                max=i;
                str=str2+str1.substr(i);
            }
        }
    }
    return max;
    
}

int Solution::solve(vector<string> &A) {
    
    int n=A.size();
    while(n!=1){
    int max=INT_MIN;
    int l,r;
    string resstr;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string str;
            int res=findoverlapping(A[i],A[j],str);
            if(max<res){
                max=res;
                l=i;
                r=j;
                resstr.assign(str);
            }
            
            
            }
        }
    n--;
    
        if(max==INT_MIN){
            A[0]+=A[n];
        }else{
            A[l]=resstr;
            A[r]=A[n];
        }
        
    }
    return A[0].length();
}
