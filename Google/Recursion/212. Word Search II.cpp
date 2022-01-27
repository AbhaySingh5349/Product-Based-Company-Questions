Question Link: https://leetcode.com/problems/word-search-ii/

// Approach 1:

class Solution {
public:
    
    struct TrieNode{
        char ch;
        TrieNode *child[26];
        int wordEnd;
        int index; // original index of word ending at this node 
        int count; // count of words having with current char being part of it
    };
    
    TrieNode *root;
    
    TrieNode *createNode(int idx){
        TrieNode *cur = new TrieNode;
        cur->ch = 'a'+idx;
        for(int i=0;i<26;i++) cur->child[i]=NULL;
        cur->wordEnd=0, cur->count=0;
        cur->index=-1;
        
        return cur;
    }
    
    void insert(string s, int k){
        TrieNode* cur=root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=createNode(idx);
            
            cur=cur->child[idx];
            cur->count++;
        }
        cur->wordEnd++;
        cur->index=k;
    }
    
    void erase(string s) { // pruning step
        TrieNode* cur=root;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int idx=ch-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=createNode(idx);
            
            cur=cur->child[idx];
            cur->count--;
        }
        cur->wordEnd--;
    }
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    
    void solve(vector<vector<char>>& grid, int i, int j, TrieNode *cur, set<int> &st, vector<string> &words){
        int n=grid.size(), m=grid[0].size();
        if(i<0 || j<0 || i==n || j==m || grid[i][j]=='*') return ;
        
        int idx=grid[i][j]-'a';
        if(cur->child[idx]==NULL) return;
        
        cur=cur->child[idx];
        
        TrieNode* temp=cur;
        if(cur->wordEnd>0 && cur->index!=-1){
            st.insert(cur->index);
            erase(words[cur->index]);
        }
        
        if(cur->count==0) return;
        
        char ch=grid[i][j];
        grid[i][j]='*';
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            solve(grid,x,y,temp,st,words);
        }
        grid[i][j]=ch;
    }
    
    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        root = createNode('*'-'a');
        
        for(int i=0;i<words.size();i++) insert(words[i],i);
        
        int n=grid.size(), m=grid[0].size();
        
        set<int> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(grid,i,j,root,st,words);
            }
        }
        vector<string> ans;
        
        set<int> :: iterator it;
        for(it=st.begin();it!=st.end();it++) ans.push_back(words[*it]);
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    
    bool solve(vector<vector<char>>& grid, int i, int j, string &s, int idx){
        int n=grid.size(), m=grid[0].size();
        if(idx==-1) return true;
        if(i<0 || j<0 || i==n || j==m || grid[i][j]!=s[idx]) return false;
        
        bool ans=false;
        char ch=grid[i][j];
        grid[i][j]='*';
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            ans |= solve(grid,x,y,s,idx-1);
        }
        grid[i][j]=ch; // backtrack
        
        return ans;
    }
    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        set<char> st;
        for(int k=0;k<words.size();k++){
            string s=words[k];
            char ch=s[s.length()-1];
            st.insert(ch);
        }
        map<char,vector<pair<int,int>>> mp;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=grid[i][j];
                if(st.find(ch)!=st.end()){
                    mp[ch].push_back({i,j});
                }
            }
        }
        
        vector<string> ans;
        for(int k=0;k<words.size();k++){
            string s=words[k];
            char ch=s[s.length()-1];
            vector<pair<int,int>> v=mp[ch];
            for(int i=0;i<v.size();i++){
                int x=v[i].first, y=v[i].second;
                bool found=solve(grid,x,y,s,s.length()-1);
                if(found){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
