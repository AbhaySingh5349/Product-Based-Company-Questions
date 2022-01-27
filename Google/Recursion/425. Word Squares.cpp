Question Link: https://leetcode.com/problems/word-squares/

// Approach 1:

class Solution {
public:
    
    struct TrieNode{
        char ch;
        TrieNode *child[26];
        vector<string> prefix;
        TrieNode(int idx){
            this->ch = 'a'+idx;
            for(int i=0;i<26;i++) this->child[i]=NULL;
            prefix.clear();
        }
    };
    
    TrieNode *root;
    
    void insert(string s){
        TrieNode *cur = root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) cur->child[idx] = new TrieNode(idx);
            cur=cur->child[idx];
            cur->prefix.push_back(s);
        }
    }
    
    vector<string> search(string s){
        TrieNode *cur = root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) return {};
            cur=cur->child[idx];
        }
        return cur->prefix;
    }
    
    void solve(vector<string> &words, vector<string> &v, int len, int maxLen, vector<vector<string>> &ans){
        if(len==maxLen){
            ans.push_back(v);
            return;
        }
        
        string cur="";
        for(int i=0;i<v.size();i++) cur += v[i][len];
        
        vector<string> prefix = search(cur);
        
        for(int i=0;i<prefix.size();i++){
            v.push_back(prefix[i]);
            solve(words,v,len+1,maxLen,ans);
            v.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string> &words) {
        vector<vector<string>> ans;
        
        root = new TrieNode('*'-'a');
        for(int i=0;i<words.size();i++) insert(words[i]);
        
        for(int i=0;i<words.size();i++){
            vector<string> v;
            v.push_back(words[i]);
            
            int len=words[i].length();
            solve(words,v,1,len,ans);
        }
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    
    void solve(vector<string> &words, vector<string> &v, int len, map<string,vector<string>> &mp, int maxLen, vector<vector<string>> &ans){
        if(len==maxLen){
            ans.push_back(v);
            return;
        }
        
        string cur="";
        for(int i=0;i<v.size();i++) cur += v[i][len];
        
        if(mp.find(cur)!=mp.end()){
            vector<string> prefix=mp[cur];
            for(int i=0;i<prefix.size();i++){
                v.push_back(prefix[i]);
                solve(words,v,len+1,mp,maxLen,ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> wordSquares(vector<string> &words) {
        vector<vector<string>> ans;
        
        map<string,vector<string>> mp;
        for(string word : words){
            for(int j=0;j<word.length();j++){
                string pre=word.substr(0,j);
                mp[pre].push_back(word);
            }
        }
        
        for(int i=0;i<words.size();i++){
            vector<string> v;
            v.push_back(words[i]);
            
            int len=words[i].length();
            solve(words,v,1,mp,len,ans);
        }
        return ans;
    }
};
