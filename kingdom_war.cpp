
/*** if want to return matrix o(n^3)
int Kadane(vector<int> v, int* start, int* finish, int n){
    int localstart=-1; 
    *finish=-1;
    int maxsum=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        if(sum<0){
            sum=0;
            localstart=i+1;
        }else if(sum>maxsum){
            maxsum=sum;
            *start=localstart;
            *finish=i;
        }
    }
    if(*finish!=-1){
        return maxsum;
    }
    //if all val negative
    maxsum=v[0];
     *start=*finish=0;

    for(int i=0;i<n;i++){
        if(maxsum<v[i]){
            maxsum=v[i];
            *start=*finish=i;
        }
    }
    return maxsum;
}

int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();

    int finalleft,finalright,finaltop,finalbottom;
    int left,right,i;
    int sum,start,finish,maxsum=INT_MIN;
    //fixing left col
    for(left=0;left<m;left++){
        vector<int> temp(n,0);
    //fixing right col
        for(right=left;right<m;right++){
           //calculating sum between left and right col for every row i
            for(i=0;i<n;i++)
                temp[i]+=A[i][right];
                sum=Kadane(temp,&start,&finish,n);
                
                if(sum>maxsum){
                    maxsum=sum;
                    finalleft=left;
                    finalright=right;
                    finaltop=start;
                    finalbottom=finish;
                    
                }
            
        }
    }
    
    return maxsum;
    
    
}
****/


//O(n^2)


int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> row_sum=A;
    
    for(int i=0;i<n;i++){
        for(int j=m-2;j>=0;j--){
            row_sum[i][j]=A[i][j]+row_sum[i][j+1];
        }
    }

    int maxsum=A[n-1][m-1];
    int rightsum;
    int downsum;
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            rightsum=0;
            downsum=0;
            if(i!=n-1){
                rightsum=dp[i+1][j];
            }
            if(j!=m-1){
                downsum= row_sum[i][j+1];
            }
            dp[i][j]+=A[i][j]+rightsum+downsum;
            maxsum=max(maxsum,dp[i][j]);
        }
    }
    



    return maxsum;
    
    
}
