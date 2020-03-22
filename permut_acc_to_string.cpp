vector<int> Solution::findPerm(const string A, int B) {
    
    vector<int> s;
    vector<int> v;
    for(int i=1;i<=A.length();i++){
        if(A[i-1]=='I'){
            s.push_back(i);
            while(!s.empty()){
                int b=s.back();
                s.pop_back();
                v.push_back(b);
            }
        }else{
            s.push_back(i);
        }
    }
    
   s.push_back(A.length()+1);
   while(!s.empty()){
       int b=s.back();
       s.pop_back();
       v.push_back(b);
   }
    
    
   return v; 
}
