#include<bits/stdc++.h>
list<int>* adj;

bool isCyclicUtil(int v, vector<bool> visited, vector<bool>& recStack){
    
    if(visited[v]==false){
    visited[v]=true;
    recStack[v]=true;
    
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i] && isCyclicUtil(*i,visited,recStack)){
            return true;
        }else if(recStack[*i]){
            return true;
        }
    
    }
    }
    recStack[v]=false;
    return false;
}

bool isCyclic(int A){
    
    vector<bool> visited(A,false);
    vector<bool> recStack(A,false);
    
    for(int i=0;i<A;i++){
        if(isCyclicUtil(i,visited,recStack)){
            return true;
        }
        
    }
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    adj=new list<int>[A];
    for(int i=0;i<B.size();i++){
        adj[B[i]-1].push_back(C[i]-1);
    }
    
    
    if(isCyclic(A)){
        return 0;
    }
    else{
        return 1;
    }
    
}
