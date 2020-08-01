int X[]={2,2,1,1,-1,-1,-2,-2};
int Y[]={1,-1,2,-2,2,-2,1,-1};


int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    vector<vector<bool>> visited(A+1,vector<bool>(B+1,false));
    
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(C,D,0));
    
    visited[C][D]=true;
    int newx,newy;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int dis=get<2>(q.front());
        q.pop();
  //  cout<<x<<" "<<y<<" "<<dis<< " ";
        if(x==E && y==F){
            return dis;
        }
    
        for(int i=0;i<8;i++){
            newx=x+X[i];
            newy=y+Y[i];
            if((newx<=A && newx>=1 )&& (newy<=B && newy>=1) && !visited[newx][newy]){
            visited[newx][newy]=true;
            q.push(make_tuple(newx,newy,dis+1));
        
        
        }
        
        }
        
        
        
        
    }
    
    
    
    return -1;
}
