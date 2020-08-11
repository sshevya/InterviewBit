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
