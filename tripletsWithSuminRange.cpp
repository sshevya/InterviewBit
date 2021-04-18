int Solution::solve(vector<string> &A){
    
    int n = A.size();
    
    if(n<3){
        return 0;
    }
    vector<float> v;
    for(int i=0;i<n;i++){
        float temp=stof(A[i]);
        v.push_back(temp);
    }
    float sum=0;
    
    float a=v[0],b=v[1],c=v[2];
    sum=a+b+c;
    
    for(int i=3;i<n;i++){
        
        if(a+b+c<2 && a+b+c>1){
            return 1;
        }
        
        
        if(a+b+c>2){
            
            if(a>b && a>c){
                a=v[i];
            }
            else if(b>a && b>c){
                b=v[i];
            }else{
                c=v[i];
            }
            
        }
        else if(a+b+c<1){
            
            if(a<b && a<c){
                a==v[i];
            }else if(b<a && b<c ){
                b=v[i];
            }else{
                c=v[i];
            }
            
            
            
        }
        
        
    }
      if(a+b+c<2 && a+b+c>1){
            return 1;
        }
        
    return 0;
}
