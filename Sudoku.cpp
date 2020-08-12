bool inRow(vector<vector<char>> &a, int row, char num){
    for(int i=0;i<9;i++){
        if(a[row][i]==num){
            return true;
        }
    }
    return false;
}
bool inCol(vector<vector<char>> &a, int col, char num){
    for(int i=0;i<9;i++){
        if(a[i][col]==num){
            return true;
        }
    }
    return false;
}
bool inBox(vector<vector<char>> &a, int boxstartx, int boxstarty, char num){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            
        if(a[i+boxstartx][j+boxstarty]==num){
            return true;
        }
    }
    }
    return false;
}


bool check(vector<vector<char>> & a, int row, int col, char num){
    if(!inRow(a,row,num) && !inCol(a,col,num) && !inBox(a,row-row%3, col-col%3, num) && a[row][col]=='.'){
        return true;
    }
    else 
    return false;
}

bool FindUnassigned(vector<vector<char>>&a, int& i, int & j){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(a[row][col]=='.'){
                i=row;
                j=col;
                return true;
            }
        }    
    
    }
    return false;
}
bool solve(vector<vector<char>> &a){
    
    int row,col;
    if(!FindUnassigned(a,row,col)){
        return true;
    }
    //cout<<row<<col;
    for(int i=1;i<=9;i++){
        string s=to_string(i);
                char c=s[0];

    if(check(a,row,col,c)){

        a[row][col]=c;
            if(solve(a)){
                return true;
            }
            
            a[row][col]='.';
        }
        
        
    }
    return false;
}



void Solution::solveSudoku(vector<vector<char> > &A) {
   
   
   solve(A);
   return ;
}
