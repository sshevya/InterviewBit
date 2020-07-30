int find(int realx, int realy, vector<string> &A, int n ,int m){
    int X[]={1,1,1,-1,-1,-1,0,0};
    int Y[]={1,-1,0,0,1,-1,1,-1};
    int count=0;
    for(int i=0;i<8;i++){
    int x=realx;
    int y=realy;
    while(x<n && y<m && x>=0 && y>=0){
        x+=X[i];
        y+=Y[i];
        
        if(x<n && y<m && x>=0 && y>=0 && A[x][y]=='1'){
            count++;
            break;
        }
    }
    }
    return count;
}



vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    
    int n=A.size();
    int m=A[0].length();
    
    vector<vector<int>> v(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=find(i,j,A,n,m);
        }
    }
    
    return v;
    
    
    
}
