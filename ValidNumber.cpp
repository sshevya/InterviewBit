int Solution::isNumber(const string A) {

    int n=A.length();
    
    int e=0;
    int dec=0;
    int k=0;
    while(A[k]==' '){
        k++;
    }
    int p=n-1;
    while(A[p]==' '){
        p--;
    }
    if(A[k]=='-'|| A[k]=='+'){
        k++;
    }
    if(k>p){
        return 0;
    }
    
    
    if(k==p && (A[p]-'0'>9 || A[p]-'0'<0)){
        return 0;
    }
    for(int i=k;i<=p;i++){
        if(A[i]-'0'<0  || A[i]-'0' >9 ){
//                                cout<<i;

            if(A[i]=='.'){
                if(dec>=1){
                    return 0;
                }else{
                    if(e==1){
                        return 0;
                    }
                    dec++;
                }
            }else if(A[i]=='e'){
                if(e>=1){
                    return 0;
                }else  if(dec==1 && A[i-1]=='.'){
                return 0;
                }
                
                e++;
            }else{
                
                if(A[i]=='-' || A[i]=='+'){
                    if(e==0){
                        return 0;
                    }else if(A[i-1]!='e'){
                        return 0;
                    }
                }else{
                    return 0;
                }
                
            }
        }
    }
    
    if(A[p]=='.'){
        return 0;
    }
    
    return 1;
    
    
}
