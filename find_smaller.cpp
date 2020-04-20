/* NAIVE APPROACH
vector<int> Solution::prevSmaller(vector<int> &A) {
    
    vector<int> g;
    g.push_back(-1);
    stack<int> s;
    s.push(A[0]);
    int n=A.size();

    for(int i=1;i<n;i++){
        
     
        int j=i-1;
        while(j>=0 && A[i]<=A[j]){
            j--;
        }
        if(j==-1){
            g.push_back(-1);
        }else{
            g.push_back(A[j]);
        }
        
          
        
    }
    
    return g;
}
*/


vector<int> Solution::prevSmaller(vector<int> &A) {
    
    vector<int> g;
    g.push_back(-1);
    stack<int> s;
    s.push(A[0]);
    int n=A.size();
    int min=A[0];
    for(int i=1;i<n;i++){
        
        
        while( !s.empty() && A[i]<=s.top()  ){
                s.pop();
        }
        
        if(!s.empty()){
            int a=s.top();
            g.push_back(a);
        }else{
            g.push_back(-1);
         }
        
        
        s.push(A[i]);
        
    }
    
    return g;
}

