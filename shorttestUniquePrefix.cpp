/*struct Trie{
    bool endofword;
    //int freq;

    unordered_map<char, Trie*> children;
    Trie(bool word) : endofword (word){
    }
};
*/
struct Trie{
    int freq;
    unordered_map<char, Trie*> children;
};


struct Trie* newnode(){
    Trie* newn=new Trie();
    newn->freq=1;
    for(int i=0;i<26;i++){
        (newn->children)['a'+i]=NULL;
    }
    return newn;
}




void constructTrie(Trie* root, vector<string> goodword){
    
    Trie* temp=root;
    
    for(int i=0;i<goodword.size();i++){
        temp=root;
        
        for(int j=0;j<goodword[i].length();j++){
            
            auto it=(temp->children).find(goodword[i][j]);
            if(it!=(temp->children).end()){
               // (temp->children)[goodword[i][j]->freq+=1;
               it->second->freq++;
                temp=it->second;
            }else{
                Trie* B=new Trie();
                B->freq=1;
                (temp->children)[goodword[i][j]]=B;
                temp=B;
            }
            
        }
    }
    
}



void prefixutil(Trie* A, string& s, vector<string>& v, string list){
    if(A==NULL){
        return;
    }
    
    if(A->freq==1){
        if(find(v.begin(),v.end(),s)==v.end())
        v.push_back(s);
        return;
    }
    //Trie* temp=A;
    //if want simply sorted array and not in the same order run for loop for i =0 to 25 and last parameter list and loop in main func is not needed see GFG
    for(int i=0;i<list.size();i++){
        if((A->children)[list[i]]!=NULL){
            string temp=s;
            char c=list[i];
            s+=c;
            prefixutil((A->children)[c], s, v,list.substr(i+1));
            s=temp;
        }
    break;//Order different without break statement
    }
    return;
}

vector<string> Solution::prefix(vector<string> &A) {
    Trie* root = new Trie();
    root->freq=0;
    constructTrie(root,A);
    Trie* temp=root;
string s="";
    vector<string> result;
    for(int i=0;i<A.size();i++){
    prefixutil(root,s,result,A[i]);
    }
    return result;
}
