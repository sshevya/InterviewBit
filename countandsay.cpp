string Solution::countAndSay(int A) {
    
    vector<string> v;
    v.push_back(to_string(1));
    
     for(int i=1;i<A;i++){
         string s=v[i-1];
         string news="";
         for(int j=0;j<s.length();j++){
            int count=1;
                 while(s[j+1]==s[j]){
                     j++;
                     count++;
                 }
                news+=to_string(count);
                news+=s[j];
    
             
         }
         v.push_back(news);
     }
    
    
    
    return v[A-1];
}
