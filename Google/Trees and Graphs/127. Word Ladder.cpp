Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
    int ladderLength(string src, string dst, vector<string>& wordList) {
        set<string> st;
        for(int i=0;i<wordList.size();i++) st.insert(wordList[i]);
        
        if(st.find(src)==st.end()){
            wordList.push_back(src);
            st.insert(src);
        }
        
        map<string,vector<string>> graph;
        for(int i=0;i<wordList.size();i++){
            string u=wordList[i]; 
            string temp=u;
            for(int j=0;j<u.length();j++){
                char ch=u[j];
                for(char cur='a';cur<='z';cur++){
                    temp[j]=cur;
                    if(st.find(temp)!=st.end()){
                        graph[u].push_back(temp);
                        graph[temp].push_back(u);
                    }
                    temp[j]=ch;
                }
            }
        }
        
        set<string> visited;
        visited.insert(src);
        
        queue<string> q;
        q.push(src);
        
        int len=1;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                string u=q.front();
                q.pop();
                
                if(u==dst) return len;
                
                for(string v : graph[u]){
                    if(visited.find(v)==visited.end()){
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
            len++;
        }
        return 0;
    }
};
