int Solution::solve(int n) {
    
    long long  color_3=24; // 24 combinations when 1st col has all three diff colors
    long long color_2=12; //12 combinations with 2 col in 1st column
    long long temp=0;
    for(int i=2;i<=n;i++){
        temp=color_3;
        color_3=(11*color_3+10*color_2)%1000000007;
        color_2=(5*temp+7*color_2)%1000000007;
        
        
    }
    
    long long ans=(color_3+color_2)%1000000007;
    
    
    return (int)ans;    
    
}
