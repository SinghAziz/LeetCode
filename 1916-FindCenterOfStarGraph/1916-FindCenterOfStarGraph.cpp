// Last updated: 30/04/2026, 19:57:39
class Solution {
public:
    int findCenter(vector<vector<int>>& graph) {
        unordered_map<int, int> mp;
        int n = 0;
        for (auto i:graph){
            mp[i[0]]++;
            mp[i[1]]++;
            n = max({i[0], i[1], n});
        }
        for (int i =0 ; i<mp.size(); i++){
            if (mp[i]==n-1) return i;
        }
    return -1;
    }
};