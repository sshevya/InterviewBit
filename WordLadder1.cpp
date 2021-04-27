/**** 
Solution 1
Multiple Concepts
don't use map, use set, else TLE
keep erasing from set because worst case time for find is linear in set
***/
int Solution::solve(string A, string B, vector<string> &C) {
    if(A==B){
        return 0;
    }
    
    unordered_set<string> m;
    for(auto x: C){
        m.insert(x);
    }
    
    queue<pair<string,int>> q;
    q.push({A,1});
    
    while(!q.empty()){
        
            string temp = q.front().first;
            int h =q.front().second;
            q.pop();
            if(temp == B){
                return h;
            }
            for(int i =0;i<temp.size();i++){
                string s = temp;
                for(char j = 'a'; j<='z'; j++){
                    s[i]=j;
                    
                    if(s==temp){
                        continue;
                    }
                    if(s==B){
                        return h+1;
                    }
                    
                    if(m.find(s)!=m.end()){
                        q.push({s,h+1});
                        m.erase(s);
                    }
                }
                
            }
            
        
    }
    return 0;
    
}

/**** See bidirectional BFS implementatoion  & concept
Solution 3 TLE




*****/

bool isAdj(string A, string B){
    int count =0;
    for(int i=0;i<A.length();i++){
        if(A[i]!=B[i]){
            count++;
        }
    }
    if(count==1){
        return 1;
    }
    return 0;
}

int Solution::solve(string A, string B, vector<string> &C) {
    if(A==B){
        return 0;
    }
    int n = C.size();
    unordered_map<string,int> m,m1,m2;
    for(auto x: C){
        m[x]=1;
    }
    
    queue<pair<string, int>> q1,q2;
    
    q1.push({A,1});
    m1[A]=1;
    q2.push({B,1});
    m2[B]=1;
    while(!q1.empty() && !q2.empty()){
        
        string temp1 = q1.front().first;
        int  h1 = q1.front().second;
        
        q1.pop();
        string temp2 = q2.front().first;
        int  h2 = q2.front().second;
        q2.pop();

        for(int i=0; i<n; i++){
         //   cout<<isAdj(C[i],temp1)<<" ";
            if(isAdj(C[i],temp1) && m1.find(C[i])==m1.end() ){
                
                if(C[i]==B){
                    return h1+1;
                }
                
                q1.push({C[i],h1+1});
                m1[C[i]]=h1+1;
                
                if(m2.find(C[i])!=m2.end()){
                    return m1[C[i]] + m2[C[i]]-1;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(isAdj(C[i],temp2) && m2.find(C[i])==m2.end() ){
                
                if(C[i]==B){
                    return h2+1;
                }
                
                q2.push({C[i],h2+1});
                m2[C[i]]=h2+1;
                
                if(m1.find(C[i])!=m1.end()){
                    return m1[C[i]] + m2[C[i]]-1;
                }
            }
        }
        
        
        
    }
    
    
    
    return 0;
}


/********** TLE  Solution(3) *****/
bool isAdj(string A, string B){
    int count=0;
    int n=A.length();
    for(int i=0;i<n;i++){
        if(A[i]!=B[i]){
            count++;
        }
        if(count>1){
            return false;
        }
    }
    
    return true;
}


int Solution::solve(string A, string B, vector<string> &C) {
             /*   if(find(C.begin(),C.end(),word)==C.end()){
                        return 0;
                }*/
    int n=C.size();
    vector<bool> v(n,false);
    queue<pair<string,int>> q;
    q.push(make_pair(A,1));
    
    while(!q.empty()){
        string s=q.front().first;
        int dis=q.front().second;
        q.pop();
        if(s==B){
            return dis; 
        }
        if(isAdj(s,B)){
            return dis+1;
            
        }
        
        
        for(int i=0;i<n;i++){
            if(!v[i] && isAdj(s,C[i])){
                q.push(make_pair(C[i],dis+1));
                v[i]=true;
            }
        }
    }
    
    
    
    return -1;
}
