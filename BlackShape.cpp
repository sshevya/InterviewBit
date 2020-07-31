void check(vector<string> & A, int realX, int realY, int n,int m){
    int X[]={1,0,0,-1};
    int Y[]={0,1,-1,0};
    
    int x=realX; int y=realY;
        
    
        
        if(realX>=n || realY >=m || realX<0 ||realY<0){
            return;
        }
        
     if(x<n && y< m && x>=0 && y>=0 && A[x][y]=='X'){
         A[x][y]='O';
     

        check(A,x+1,y,n,m);
        check(A,x-1,y,n,m);
        check(A,x,y+1,n,m);
        check(A,x,y-1,n,m);
     }
}



int Solution::black(vector<string> &A) {
    
    int n=A.size();
    int m=A[0].length();
    int count=0;
    //vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='X'){
                check(A,i,j,n,m);
                count++;
               //cout<<countX(A)<<" ";
            }
        }
    }
    return count;
}
