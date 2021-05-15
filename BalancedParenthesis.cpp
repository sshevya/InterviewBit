/**** can also be done in O(1) space. keep a counter in place of stack****/

int Solution::solve(string A) {
    
    int n = A.length();
    
    stack<char> s;
    
    for(int i=0;i<n;i++){
        if(A[i]=='('){
            s.push(A[i]);
        }else{
            if(!s.empty()){
                s.pop();
            }else{
                return 0;
            }
        }
    }
    if(!s.empty()){
        return 0;
    }
    
    return 1;
}
