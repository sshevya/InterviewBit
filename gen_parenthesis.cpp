void backtrack(int A, int open,int rem, vector<string>& v, string& s){
    if(rem==0 && open==0){
        v.push_back(s);
        return;
    }
    
    if(open>0){
        s+=')';
        backtrack(A,open-1,rem,v,s);
        s.erase(s.size()-1);
        
    }
    
    if(rem>0){
        s+='(';
        backtrack(A,open+1,rem-1,v,s);
        s.erase(s.size()-1);
    }
    
    
}




vector<string> Solution::generateParenthesis(int A) {
    vector<string> v;
    string s="";
    backtrack(A,0,A,v,s);
    sort(v.begin(),v.end());
    return v;
}
