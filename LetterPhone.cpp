/****Sol using BFS **/
vector<string> Solution::letterCombinations(string A) {
    
    int n=A.length();
    string table[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; 

    vector<string> ans;
    if(n==0){
        return ans;
    }
  //  if(n==1 )
    
    queue<string> q;
    q.push(table[A[0]]);
   while(!q.empty()){
           string s=q.front();
           q.pop();
           if(s.length()==n){
               ans.push_back(s);
           }
           else{
               
               for(auto letter: table[A[s.length()]-'0']){
                 /*  if(letter==0){
                       q.push("0");
                   }else if(letter==1){
                       q.push("1");
                   }else{*/
                  // cout<<A[s.length()]<<"5";
                   q.push(s+letter);
               
               }
               
               
           }
           
           
           
       }
        
        
       return ans;
    
    
    
}

/***Sol using backtracking ***/
void bc(string table[],string& s, string& A, vector<string>& v, int ind){
    if(s.length()==A.length()){
        v.push_back(s);
        return;
    }
    
    if(ind>=A.length()){
        return;
    }
    
        for(char a : table[A[ind]-'0']){
            s+=a;
            bc(table,s,A,v,ind+1);
            s.pop_back();
            
        }
        

}

vector<string> Solution::letterCombinations(string A) {
    
    int n=A.length();
    string table[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; 

    string s="";
    vector<string> v;
    bc(table,s,A,v,0);
    
    return v;
}

