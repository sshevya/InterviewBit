vector<vector<int> > Solution::generateMatrix(int A) {
  
  int i=0,j=0;
   int check=0;
   int count=0;
   for(int p=1;p<=A*A;p++){
       
       /*if(v[i][j]!=0){
          if(check==0){
              check=1;
          } else if(check==1){
              check=2;
          }else if(check==2){
              check=3;
          }else{
              check=0;
          }
       }*/
       if(v[i][j]!=0){
           i++;
           j++;
       }
       v[i][j]=p;
       if(check==0){
           j++;
           if(j==A-1-count){
               check=1;
           }
       }else if(check==1){
           
            i++;
           if(i==A-1-count){
               check=2;
           }
           
       }else if(check==2){
           
           j--;
           if(j==count){
               check=3;
           }
           
           
       }else if(check==3){
           i--;
           if(i==count){
               check =0;
               count++;
           }
           
       }
       
       
   }
   return v;
  
  
  
  
  
  
  /***************** Another approach (difficult)
   vector<vector<int>> v; 
   vector<int> m(A,0);
   for(int i=0;i<A;i++){
       v.push_back(m);
   }
    int x=0,y=0;
    int sizeleft=A-1;
    int boundary=A-1;
    char move='r';
    int flag=1;
    for(int i=1;i<A*A+1;i++){
        v[x][y]=i;
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
        
        if(i==boundary){
            boundary+=sizeleft;
            if(flag!=2){
                flag=2;
            }else{
                flag=1;
                sizeleft--;
            }
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
        
    }
    
  return v;*************/ 
}
