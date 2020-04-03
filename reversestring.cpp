string removespace(string A){
    string s="";
    for(int i=0;i<A.length();i++){
        if(A[i]!=' '){
            s+=A[i];
        }
    }
    return s;
}
string Solution::solve(string A) {
    
    int n=A.length();
    if(n==1){
        return A;
    }
    vector<int> v;
    int j=0;
    while(A[j]==' '){
        A.erase(A.begin());
        j++;
    }
    j=n-1;
     while(A[j]==' '){
        A.erase(A.end());
        j--;
    }
    int count=0;
    
    for(int i=0;i<n;i++){
        if(A[i]==' '){
             v.push_back(count);
            count=0;
        }else if(i==n-1){
            v.push_back(count+1);
            count=0;
        }
        else{
            count++;
        }
    }
    
   /* for(int i=0;i<v.size();i++){
        cout<<v[i];
    }*/
    
    string news=removespace(A);
    reverse(news.begin(),news.end());
    string finals="";
    int vlen=v.size();
    int k=vlen-1;
    count=v[k];
    int count2=0;
    for(int i=0;i<news.length();i++){
        finals+=news[i];
        count2++;
        if(count2==count){
            finals+=' ';
    
            k=k-1;
            count=v[k];
            count2=0;
        }
        
    }

    int start=0;
    k=vlen-1;
    count=v[k];
//value.erase(value.begin(), std::find_if(value.begin(), value.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
    for(int i=0;i<finals.size();i++){
    
        if(finals[i]==' '){
                reverse(finals.begin()+start,finals.begin()+start+count+1);
                start=i+1;
                k=k-1;
                count=v[k];
        }
        
     }
    
  
   
   finals.erase(finals.begin(), std::find_if(finals.begin(), finals.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
   
    
    return finals;
    
}

