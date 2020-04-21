//returns 1 if not in row
int checkrow(vector<string> A, int row){ 
    
   unordered_map<char,int> m;
   
   for(int i=0;i<9;i++){
       if(m.find(A[row][i])!=m.end()){
           return 0;
       }
       if(A[row][i]!='.'){
           m[A[row][i]]=1;
       }
   }
   
   
   return 1;
}

int checkcol(vector<string> A, int col){
    unordered_map<char,int> m;
   
   for(int i=0;i<9;i++){
       if(m.find(A[i][col])!=m.end()){
           return 0;
       }
       if(A[i][col]!='.'){
       m[A[i][col]]=1;
       }
   }
   
   
   return 1;
}

int checkbox(vector<string> A, int row, int col){
    
    unordered_map<char,int> m;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(m.find(A[i+row][j+col])!=m.end()){
                return 0;
            }
            if(A[i+row][j+col]!='.'){
            m[A[i+row][j+col]]=1;
            }
        }
    }
    
    return 1;
}







int Solution::isValidSudoku(const vector<string> &A) {
    
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(!(checkrow(A,i)&& checkcol(A,j)&& checkbox(A,i-i%3,j-j%3))){
                return 0;
            }
        }
    }
    
    
    
    
  return 1;  
}
