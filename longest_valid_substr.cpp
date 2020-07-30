int Solution::longestValidParentheses(string str) {
    	int n = str.length(); 

	stack<int> stk; 
	stk.push(-1); 

	int result = 0; 
	for (int i=0; i<n; i++) 
	{ 
		// If opening bracket, push index of it 
		if (str[i] == '(') 
		stk.push(i); 
		
		else // If closing bracket, i.e.,str[i] = ')' 
		{ 
		

			stk.pop(); 



			if(!stk.empty()){
                result=max(result,i-stk.top());
			}
			else{
			    stk.push(i);
			}

	

		} 
	} 

	return result; 
}



/********DP Sol

int Solution::longestValidParentheses(string str) {
     int n = str.length(); 
  
    int dp[n+1]={0};
    dp[0]=0;
    //dp[1]=0;
   int maxm=0;
    for(int i=1;i<n;i++){
if(str[i]==')' && i-dp[i-1]-1>=0 && str[i-dp[i-1]-1]=='('){
            dp[i]=dp[i-1]+2+((i-dp[i-1]-2>=0)?dp[i-dp[i-1]-2]:0);
                            maxm=max(maxm,dp[i]);

        }

    }




return maxm;;
}
********/
