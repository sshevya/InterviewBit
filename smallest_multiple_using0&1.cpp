int findremainder(string s, int n){

    int val=0;
    for(int i=0;i<s.length();i++){
        val=val*10+(s[i]-'0');
        val=val%n;
    }
    return val;
}


string Solution::multiple(int A) {

    
    vector<int> visit(A+1,0);
    vector<int> parent(A+1,-1);
    vector<int> val(A+1,-1);
    
    queue<int> q;
    q.push(1%A);
    visit[1%A]=1;
    parent[1%A]=-1;
    val[1%A]=1;
    while(!q.empty()){
         int temp=q.front();
         q.pop();
         if(temp==0){
                              string s="";

             while(temp!=-1){
                 
                 s+=to_string(val[temp]);
                 temp=parent[temp];
             }
             reverse(s.begin(),s.end());
             return s;
         }
         
         
         int val1=temp*10%A;
         int val2=(temp*10+1)%A;
         
         if(visit[val1]==0){
             visit[val1]=1;
             parent[val1]=temp;
             val[val1]=0;
             q.push(val1);
         }
         
         if(visit[val2]==0){
             visit[val2]=1;
             parent[val2]=temp;
             val[val2]=1;
             q.push(val2);
         }
        
        
    }
    
    
}
