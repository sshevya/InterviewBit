/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 
vector<Interval> Solution::merge(vector<Interval> &A) {

    int n=A.size();
    vector<Interval> s;

    //cout<<A[0].start<<" "<<A[0].end;
    sort(A.begin(), A.end(), compareInterval); 
        s.push_back(A[0]);
    for(int i=1;i<n;i++){
        Interval top=s.back();
        
        if(top.end<A[i].start){
            s.push_back(A[i]);
        }
        else if(top.end<A[i].end){
            top.end=A[i].end;
            s.pop_back();
            s.push_back(top);
        }
    }
    
    
    
    return s;
    
}
