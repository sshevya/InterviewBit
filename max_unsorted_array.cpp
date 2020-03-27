vector<int> Solution::subUnsort(vector<int> &A) {
    
   int n=A.size();
   vector<int> v;
   int s,e,i,j;
   for( i=0;i<n-1;i++){
       if(A[i]>A[i+1]){
         
           break;
       }
   }
   s=i;
   if(s==n-1){
       v.push_back(-1);
       return v;
   }
   for( j=n-1;j>0;j--){
       if(A[j]<A[j-1]){
          
           break;
       }
   }
   e=j;
   int max=A[s];
   int min=A[s];
   for(int k=s+1;k<=e;k++){
       if(A[k]<min){
           min=A[k];
       }else if(A[k]>max){
           max=A[k];
       }
   }
   for(i=0;i<s;i++){
       if(A[i]>min){
           s=i;
           break;
       }
   }
   for(i=n-1;i>=e+1;i--){
       if(A[i]<max){
           e=i;
           break;
       }
   }
    
    v.push_back(s);
    v.push_back(e);
    
   return v; 
}
