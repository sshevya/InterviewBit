/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    map<UndirectedGraphNode*,UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    
    UndirectedGraphNode* s=new UndirectedGraphNode(node->label);
    
    m[node]=s;
    
    while(!q.empty()){
        
        UndirectedGraphNode* top=q.front();
        q.pop();
        
        vector<UndirectedGraphNode*> v=top->neighbors;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(m[v[i]]==NULL){
            UndirectedGraphNode* temp=new UndirectedGraphNode(v[i]->label);
            m[v[i]]=temp;
            q.push(v[i]);
            }
            
            m[top]->neighbors.push_back(m[v[i]]);
            
        }
        
        
        
        
        
    }
    
    return m[node];
    

}
