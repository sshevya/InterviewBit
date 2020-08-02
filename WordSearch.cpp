
/**********IF CELL CANT BE USED TWICE


int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
bool DFS(int x, int y, vector<string> & A,string B){
  if(A[x][y]==B[0]){
      int nx,ny;
      int j;
      for(int i=0;i<4;i++){
          nx=x+X[i];
          ny=y+Y[i];
          for(j=1;j<B.length();j++){
              
              if(nx<0 || ny<0 || nx>=A.size() || ny>=A[0].length()){
                  break;
              }
              if(A[nx][ny]!=B[j]){
                  break;
              }else{
                nx+=X[i];
              ny+=Y[i];
            
          }
          }
          if(j==B.length()){
              return true;
          }
      }
      
  }  
      return false;
  
}




int Solution::exist(vector<string> &A, string B) {
    

    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].length();j++){
            if(DFS(i,j,A,B)){
                return 1;
            }
        }
    }
    
    return 0;
}
*************/
/**IF CELL CAN BE USED TWICE***/



int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
bool DFS(int in,int x, int y, vector<string> & A,string B){
  if(in==B.size()){
      return true;;
  }
  //int nx=x;
  //int ny=y;
  for(int i=0;i<4;i++){
      //nx=x+X[i];
      //ny=y+Y[i];
      if(x+X[i]<0 || y+Y[i]<0 || x+X[i]>=A.size()|| y+Y[i]>=A[0].length()){
          continue;
      }
      if(A[x+X[i]][y+Y[i]]==B[in]){
        if(DFS(in+1,x+X[i],y+Y[i],A,B)){
            return true;
        }
        
      }
  }
  
  
return false;

}

int Solution::exist(vector<string> &A, string B) {
    
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==B[0]){
            if(DFS(1,i,j,A,B)){
                return 1;
            }
            }
        }
    }
    
    return 0;
}
