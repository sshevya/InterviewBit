
/**********************IMP***********/
int X[]={0,0,1,-1};
int Y[]={1,-1,0,0};
void DFS(int x, int y,vector<vector<char>>& mat,int N, int M){
    //int N=mat[0].size();
    //int M=mat.size();
    int nx, ny;
   /* if((x==0 || x== M-1 || y==0 || y== N-1 )&& mat[x][y]=='O'){
        return false;
    }
    if((x==0 || x== M-1 || y==0 || y== N-1 )&& mat[x][y]=='X'){
        return true;
    }*/
    mat[x][y]='-';
    //cout<<x<<" "<<y<<" ";
        for(int i=0;i<4;i++){
            nx=x+X[i];
            ny=y+Y[i];
           /* while(ny>=0 && ny<N && nx>=0 && nx<M){
                nx+=X[i];
                ny+=Y[i];
            if((ny==0 || ny==N-1 || nx==0 || nx==M-1) && mat[nx][ny]=='O')
                    check=false;
            
            }*/          //     cout<<nx<<" "<<ny<<" ";

            if(ny>=0 && ny<N && nx>=0 && nx<M && mat[nx][ny]=='O')
               
                            DFS(nx,ny,mat,N,M);

             
            }

        
    
}



void Solution::solve(vector<vector<char> > &A) {
       int N= A.size();
       int M=A[0].size();
               bool check=true;
if(N==1 && M==1){
    return;
}
       for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if((i==0 || j==0 || i==N-1 || j==M-1 )&&A[i][j]=='O'){
                DFS(i,j,A,M,N);
            }
        }
    }
    
     for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]=='-'){
                A[i][j]='O';
            }else{
                A[i][j]='X';
            }
        }
     }
    return;
    }
