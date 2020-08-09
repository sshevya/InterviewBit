/*void heapify(vector<int>& v, int n, int i ){
    
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && v[l]<v[smallest]){
        smallest=l;
    }
    if(r<n && v[r]<v[smallest]){
        smallest=r;
    }
    
    if(smallest!=i){
        swap(&v[smallest],v[i]);
        heapify(v,n,smallest);
    }
}

void buildheap(vector<int>& v){
    
    int n=v.size();
    int start=n/2-1;
    
    for(int i=start;i>=0;i--){
        heapify(v,n,i);
    }

}
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
        int n=A.size();
            vector<int> v;
    //priority_queue<int, vector<int>, greater<int>> pq;;
    map<int, int> m;
    int count=0;
    for(int i=0;i<B;i++){              

      if(m[A[i]]==0){
count++;
      }
        m[A[i]]+=1;
              //  if(start==4)
    }
    int start=0;int k=B;
v.push_back(count);
    while(k<n){
        
    
        

        if(m[A[start]]>1){
        m[A[start]]--;
        }
        else if(m[A[start]]==1){
            count--;
            m[A[start]]-=1;
        }
        
        start++;

    if(m[A[k]]==0){
          count++;
      }
        m[A[k]]+=1;
              //  if(start==4)cout<<m[A[i]];
                  k++;
        v.push_back(count);

    }
    
    return v;
    
}
