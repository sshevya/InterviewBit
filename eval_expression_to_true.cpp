int Solution::cnttrue(string A) {
    
    int n=A.length();
    vector<int> sym;
    vector<int> op;
    for(int i=0;i<n;i++){
        if(A[i]=='|' || A[i]=='&' || A[i]=='^'){
            op.push_back(A[i]);
        }else{
            sym.push_back(A[i]);
        }
    }
    int l=sym.size();
    int T[l][l]={0};
    int F[l][l]={0};
    
    for(int i=0;i<l;i++){
        
        T[i][i]=(sym[i]=='T')?1:0;
        F[i][i]=(sym[i]=='F')?1:0;
    }
    
    for(int gap=1;gap<l;gap++){
        for(int i=0,j=gap;j<l;j++,i++){
           T[i][j]=0;
           F[i][j]=0;
            for(int g=0;g<gap;g++){
                 int k = i + g; 
  
                // Store Total[i][k] and Total[k+1][j] 
                int tik = (T[i][k] + F[i][k])%1003; 
                int tkj = (T[k+1][j] + F[k+1][j])%1003; 
  
                // Follow the recursive formulas according to the current 
                // operator 
                if (op[k] == '&') 
                { 
                    T[i][j] += (T[i][k]*T[k+1][j])%1003; 
                    F[i][j] += ((tik*tkj)%1003 - (T[i][k]*T[k+1][j])%1003)%1003; 
                } 
                if (op[k] == '|') 
                { 
                    F[i][j] += (F[i][k]*F[k+1][j])%1003; 
                    T[i][j] += ((tik*tkj)%1003 - (F[i][k]*F[k+1][j])%1003)%1003; 
                } 
                if (op[k] == '^') 
                { 
                    T[i][j] += ((F[i][k]*T[k+1][j])%1003 + (T[i][k]*F[k+1][j])%1003)%1003; 
                    F[i][j] += ((T[i][k]*T[k+1][j])%1003 + (F[i][k]*F[k+1][j])%1003)%1003; 
                } 
            }
        }
    }
    
    
    
    return T[0][l-1]%1003;
    
}
