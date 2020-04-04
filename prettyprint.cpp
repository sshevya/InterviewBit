vector<vector<int> > Solution::prettyPrint(int A) {
    
    int n=2*A-1;
    
    vector<vector<int>> v(n,vector<int>(n));
   // char move='r';
    //int x=0,y=0;
    int index=0;
    int boundary=n;
    
    while(A>0){
    for(int i=index;i<boundary;i++){
        for(int j=index;j<boundary;j++){
            v[i][j]=A;
        }
    }
    A--;
    index++;
    boundary--;
    }
    
   /* 
    
    for(int i=0;i<m*m;i++){
        
        v[x][y]=A;
       
        if(i==n-1 || i== 2*n-2 || i==3*n-3){
            
            switch(move){
            case 'r':
              move='d';
              break;
            case 'l':
              move='u';
              break;
            case 'u':
              move='r';
              break;
            case 'd':
              move='l';
              break;
            }
        }
        else if(i==4*n-5){
            n=n-2;
            A=A-1;
            switch(move){
            case 'r':
              move='d';
              break;
            case 'l':
              move='u';
              break;
            case 'u':
              move='r';
              break;
            case 'd':
              move='l';
              break;
            }
            
        } 
            
            switch(move){
             case 'r':
              y+=1;
              break;
            case 'l':
              y-=1;
              break;
            case 'u':
              x-=1;
              break;
            case 'd':
              x+=1;
              break;
        }
            
        
    
    }
    */
    
    return v;
}
