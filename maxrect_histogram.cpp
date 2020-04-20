int Solution::largestRectangleArea(vector<int> &A) {
    
    int n=A.size();
    stack<int> s;
    int max_area=0;
    int top_idx;
    
    int i=0;
    while(i<n){
        if(s.empty() || A[i]>A[s.top()]){
            s.push(i);
            i++;
        }else{
            
            top_idx=s.top();
            s.pop();
            
            int curr_max=A[top_idx]*(s.empty()?i:i-s.top()-1);
            max_area=max(max_area,curr_max);
            
        }
    }
    
    while(!s.empty()){
        top_idx=s.top();
        s.pop();
        int curr_max=A[top_idx]*(s.empty()?i:i-s.top()-1);
        max_area=max(max_area,curr_max);
    }
    
    
    
    
    
    
    return max_area;
    
}
