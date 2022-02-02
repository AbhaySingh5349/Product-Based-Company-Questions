Question Link: https://leetcode.com/problems/trapping-rain-water/

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
