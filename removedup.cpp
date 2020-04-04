int Solution::removeDuplicates(vector<int> &A) {
        
    int n=A.size();
    if(n==1){
        return 1;
    }
   /* int count=1;
    for(int i=1;i<n;i++){
        if(A[i]!=A[i-1]){
            count++;
        }else{
        while(A[i]==A[i-1] && i<n){
            A.erase(A.begin()+i);
    
            
        }
        }
    }
    */
    auto end = A.end();
	for (auto it = A.begin(); it != end; ++it) {
		end = std::remove(it + 1, end, *it);
	}

	A.erase(end, A.end());

    
    
    return A.size();
}
