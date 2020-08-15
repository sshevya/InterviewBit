vector<int> Solution::plusOne(vector<int> &A) {
    
  
   
   int n=A.size();
    vector<int> v(n,0);
   v[n-1]=1;
   int  i=n-1;
   int carry=0;
   int val=0;
   while(i>=0 ){
       
       val=A[i]+v[i]+carry;
       v[i]=val%10;
       
       carry=val/10;
       i--;
       
       
   }
   
   if(carry!=0){
       v.insert(v.begin(),1);
   }
  
   while(v[0]==0){
       v.erase(v.begin());
      
   }
 return v;
}
