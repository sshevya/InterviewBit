/** was trying ot build heap first but using pq is better
void heapify(vector<int>& v,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<v.size() && v[left]>v[i]){
        largest=left;
    }
    if(right<v.size() && v[right]>v[largest]){
        largest=right;
    }
    
    if(largest!=i){
        swap(v[i],v[largest]);
        heapify(v,largest);
    }
}

void buildmaxheap(vector<int> B){
    int start=(B.size()/2);
    for(int i=start;i>=0;i--){
        heapify(B,start);
    }
}

*/

int Solution::nchoc(int A, vector<int> &B) {
   
    priority_queue<int> pq;
    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }
    int sum=0;
    for(int i=0;i<A;i++){
        int top=pq.top();
        
        sum=(sum+(top%1000000007))%1000000007;
        pq.pop();
        pq.push(top/2);
    }
        
    return sum;
}
