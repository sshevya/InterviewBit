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

/**** See bidirectional BFS implementatoion  & concept*****/


/********** TLE  Solution(2) *****/
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
