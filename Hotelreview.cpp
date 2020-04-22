struct TrieNode{
    bool endofword;
    unordered_map<char, TrieNode*> children;
    TrieNode(bool word): endofword(word) {}
};


void make_vector(string goodstring, vector<string>& goodword_vector){
    goodstring+='_';
    string temp_s="";
    for(int i=0;i<goodstring.length();i++){
        if(goodstring[i]!='_'){
            temp_s+=goodstring[i];
        }else{
            if(temp_s.length()){
                goodword_vector.push_back(temp_s);
                temp_s="";
            }
        }
    }
}

void constructTrie(TrieNode* root, vector<string> goodword){
    
    TrieNode* temp=root;
    
    for(int i=0;i<goodword.size();i++){
        temp=root;
        
        for(int j=0;j<goodword[i].length();j++){
            
            auto it=(temp->children).find(goodword[i][j]);
            if(it!=(temp->children).end()){
                temp=it->second;
            }else{
                TrieNode* B=new TrieNode(false);
                (temp->children)[goodword[i][j]]=B;
                temp=B;
            }
         
            if(j==goodword[i].size()-1){
                temp->endofword=true;
            }         
            
        }
    }
    
}

struct res {
    int index, score;
};

bool sortByScore (pair<int,int> lhs, pair<int,int> rhs) {
    if (lhs.second > rhs.second) return true;
    else if (lhs.second == rhs.second) return lhs.first < rhs.first;
    return false;
}
vector<int> sortreview(TrieNode* A, vector<string> B){
    
    TrieNode* temp=A;
    int index, score;
    vector<pair<int,int>> res;
    
    for(int i=0;i<B.size();i++){
        string  s=B[i];
        score=0;
        vector<string> v;
        make_vector(s,v);
        B[i]+="_";
        
        for(int j=0;j<v.size();j++){
            temp=A;
            for(int k=0;k<v[j].length();k++){
                auto it =(temp->children).find(v[j][k]);
                if(it==(temp->children).end()){
                    break;
                }
                temp=it->second;
                
                if(k==v[j].length()-1 && temp->endofword==true){
                    score++;
                }
            }
            
        }
        
    res.push_back(make_pair(i,score));
        
    }
    sort(res.begin(),res.end(),sortByScore);
    
    vector<int> v;
    
    for (int i=0; i<res.size(); i++) {
        v.push_back(res[i].first);
    }
    
    return v;
    
}


vector<int> Solution::solve(string A, vector<string> &B) {
    TrieNode* root = new TrieNode(false);
    vector<string> good_words;
    
    make_vector(A, good_words);
    
    constructTrie(root, good_words);
    
    vector<int> result = sortreview(root,B);
    
    return result;

    
    
    
    
}
