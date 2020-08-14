int findnextlargest(vector<int> & A, int l, int r, int val){
    int index=-1;
    int mid;
    if(l==r){
        return l;
    }
    while(l<=r){
        mid=l+(r-l)/2;
        if(val>=A[mid]){
            r=mid-1;
        }else{
            l=mid+1;
            if(index==-1 || A[index]>=A[mid]){
                index=mid;
            }
        }
    }
    return index;
}
vector<int> Solution::nextPermutation(vector<int> &A) {
    
    int n=A.size();
    int ind=-1;
    for(int i=n-2;i>=0;i--){
        if(A[i+1]>A[i]){
            ind=i;
            break;
        }
    }
    //cout<<" in"<<ind;
    if(ind==-1){
        sort(A.begin(),A.end());
        return A;
    }else{
        int right_ind=findnextlargest(A,ind+1,n-1,A[ind]);
      //  cout<<ind<<" "<<right_ind<<" "<<n;
        int temp=A[ind];
        A[ind]=A[right_ind];
        A[right_ind]=temp;
    //    swap(&A[ind],&A[right_ind]);
        sort(A.begin()+ind+1,A.end());
    }
    
    
    
    
    return A;
}
