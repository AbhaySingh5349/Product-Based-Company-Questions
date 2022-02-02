Question Link: https://leetcode.com/problems/trapping-rain-water/

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    
    int matchCount(string a, string b){
        int c=0;
        int n=a.length();
        for(int i=0;i<n;i++) if(a[i]==b[i]) c++;
        return c;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(0));
        for(int g=0;g<10;g++){
            int n=wordlist.size();
            int r=rand()%n;
            
            string mostProbable=wordlist[r];
            int matches=master.guess(mostProbable);
            if(matches==6) return;
            
            vector<string> candidates;
             for(int i=0;i<n;i++){
                 string s=wordlist[i];
                 if(matchCount(s,mostProbable)==matches){
                     candidates.push_back(s);
                 }
             }
             wordlist=candidates;
        }
    }
};
