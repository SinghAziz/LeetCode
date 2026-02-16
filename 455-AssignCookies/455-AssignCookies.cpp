// Last updated: 16/02/2026, 11:57:19
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int content = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookie=0;
        int child=0;
        while (cookie<s.size() && child<g.size() ){
            if (s[cookie] >= g[child]){
                content++;
                child++;
            }
            cookie++;
        }
        return content;
    }
};