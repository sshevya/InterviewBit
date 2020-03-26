vector<int> Solution::maxset(vector<int> &A) {
     vector<int> v;
    int n=A.size();
    if(n==1){
        if(A[0]>=0){
           v.push_back(A[0]);
           
        }
        return v;
    }
    long long int max_sum=0;
    long long int curr_max=0;
    long long int sum=0;
    int s=0,e;
    int k=0;
    while(A[k]>=0 && k<n){
    
        sum+=A[k];
        k++;
    }
    e=k;
    max_sum=sum;
   
    for(int i=k;i<n;i++){
        if(A[i]<0){
            curr_max=0;
        }else{
            int temps=i;
            sum=0;
            while(A[i]>=0 && i<n){
            
                sum+=A[i];
                i++;
            }
            int tempe=i;
            if(sum>max_sum){
                max_sum=sum;
                s=temps;
                e=tempe;
            }
            
        }
        
    }
    for(int i=s;i<e;i++){
        v.push_back(A[i]);
    }
    
    
    
    return v;
    
}
