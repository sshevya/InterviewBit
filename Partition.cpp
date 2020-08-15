int Solution::solve(int A, vector<int> &B) {
    
    int sum=0;
    vector<int> v;
    for(int i=0;i<A;i++){
        sum+=B[i];
        v.push_back(sum);    

    }
    if(sum%3!=0){
        return 0;
    }
    sum=sum/3;
    int count=0,count1=0;
    for(int i=0;i<A;i++){
        if(v[i]==sum){
            for(int j=i+1;j<A-1;j++){
                        //cout<<v[i]<<" "<<sum<<" ";

                if(v[j]==2*sum){
                    count++;
                }
            }
        }
    }
    return count;
}
