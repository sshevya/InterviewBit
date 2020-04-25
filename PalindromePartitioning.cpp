bool ispalindrome(string s,int i, int j){
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

void rec(string A, vector<string>& substring, vector<vector<string>>& v,int i){
    if( i==A.length()){
        v.push_back(substring);
    }
    
    for(int x=i;x<A.length();x++){
        if(ispalindrome(A,i,x)){
            string s=A.substr(i,x-i+1);
            substring.push_back(s);
            rec(A,substring,v,x+1);
            substring.pop_back();
        }
    }
}





vector<vector<string> > Solution::partition(string A) {
   
    vector<vector<string>> v;
    vector<string> s;
    rec(A,s,v,0);
    return v;
}
