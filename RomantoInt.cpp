int intval(char a){
 
 if(a=='I'){
     return 1;
 }else if(a=='V'){
     return 5;
 }else if(a=='X'){
     return 10;
 }else if(a=='L'){
     return 50;
 }else if(a=='C'){
     return 100;
 }
 else if(a=='D'){
     return 500;
 }else{
     return 1000;
 }
 
}
int Solution::romanToInt(string A) {
    
    
    int n=A.length();
    
    int val=0;
    int i;
    for( i=0;i<n-1;i++){
        if(intval(A[i])>=intval(A[i+1])){
            val+=intval(A[i]);
        }else{
            val=val+intval(A[i+1])-intval(A[i]);
            i++;
        }
    }
    
    if(i<n){
        val+=intval(A[n-1]);
    }
    
    
    
    return val;
    
    
}
