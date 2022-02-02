Question Link: https://leetcode.com/problems/trapping-rain-water/

// Approach 1:

class Solution {
public:
    int minAreaRect(vector<vector<int>>& a){
        int n=a.size();
        set<pair<int,int>> st;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int x1=a[i][0], y1=a[i][1];
            
            set<pair<int,int>> :: iterator it;
            for(it=st.begin();it!=st.end();it++){
                int x2=it->first, y2=it->second;
                if(st.find({x1,y2})!=st.end() && st.find({x2,y1})!=st.end()){
                    int area=abs(x1-x2)*abs(y1-y2);
                    ans=min(ans,area);
                }
            }
            st.insert({x1,y1});
        }
        return (ans==INT_MAX ? 0:ans);
    }
};

// Approach 2:

class Solution {
public:
    int minAreaRect(vector<vector<int>>& a){
        int n=a.size();
        
        map<int,vector<int>> ycordinate;
        for(int i=0;i<n;i++){
            int x=a[i][0], y=a[i][1];
            ycordinate[x].push_back(y);
        }
        
        map<pair<int,int>,int> vlines;
        
        map<int,vector<int>> :: iterator it;
        
        int ans=INT_MAX;
        for(it=ycordinate.begin();it!=ycordinate.end();it++){
            vector<int> v=it->second;
            int x1=it->first;
            
            for(int i=0;i<v.size();i++){
                int y1=v[i];
                for(int j=0;j<v.size() && i!=j;j++){
                    int y2=v[j];
                    
                    if(vlines.find({y1,y2})!=vlines.end()){
                        int x2=vlines[{y1,y2}];
                        int area=(x1-x2)*abs(y2-y1);
                        ans=min(ans,area);
                    }
                    vlines[{y1,y2}]=x1;
                    vlines[{y2,y1}]=x1;
                }
            }
        }
        return (ans==INT_MAX ? 0:ans); 
    }
};
