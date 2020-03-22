int minsteps(int a1,int a2,int b1,int b2){
    int x=abs(a1-a2);
    int y=abs(b1-b2);
    return max(x,y);
}

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int steps=0;
    int n=A.size();

    if(n==1){
        return 0;
    }
    
    for(int i=0;i<n-1;i++){
        steps+=minsteps(A[i],A[i+1],B[i],B[i+1]);
    }
    
    
    return steps;
}
