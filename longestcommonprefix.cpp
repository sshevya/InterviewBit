int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}
/*************See O(nmlogn) binary search sol GFG************/

string Solution::longestCommonPrefix(vector<string> &A) {
    
    
    int n=A.size();
    int min_l=A[0].length();
    for(int i=0;i<n;i++){
        min_l=min(min_l,A[i].length());
    }
    string lcp=A[0];
    int count=0,i,j;
    for(i=1;i<n;i++){
        count=0;
        string s="";
        for(j=0;j<min_l;j++){
           if(A[i-1][j]==A[i][j]){
               count++;
               s+=A[i][j];
           } 
        }
        min_l=count;
        lcp=s;
    }
    
    
    return lcp;
}
