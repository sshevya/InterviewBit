int Solution::maxPoints(vector<int> &A, vector<int> &B) {
   
    int n=A.size();
    if(n==1){
        return 1;
    }
    map<double,int> m;
    int count=0;
    int overlappoints=0;
    int verticalpoints=0;
    int maxp=0;
    double slope;
    for(int i=0;i<n;i++){
        m.clear();
count=verticalpoints=overlappoints=0;
        for(int j=i+1;j<n;j++){
         
          if(A[i]==A[j] &&B[i]==B[j]){
             overlappoints++;
         }
         else if(A[i]-A[j]==0){
             verticalpoints++;
         }
         else {
         slope=double(double(B[i]-B[j])/double(A[i]-A[j]));
         if(m.find(slope)==m.end()){
             m[slope]=1;
            
         }
         else{
             m[slope]+=1;
         }            
         count=max(count,m[slope]);
         }
        count=max(count,verticalpoints);
        
        }    
        maxp=max(maxp,count+overlappoints+1);
    }    
    
    
    
    
    
    return maxp;
    
}
