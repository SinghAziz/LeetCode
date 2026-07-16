// Last updated: 16/07/2026, 12:29:40
class Solution {
public:
    vector<int> parent;
    unordered_map<int, vector<char>> mp;
    string s;
    int n;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        this->s = s;
        this->n = s.size();
        parent.resize(n);
        for (int i = 0; i<n; i++) parent[i]=i;
        mp = unordered_map<int, vector<char>> (n);
        for (int i = 0; i<pairs.size(); i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            Union(u, v);
        }
        for (int i = 0; i<n; i++){
            int p = find(i);
            mp[p].push_back(s[i]);
        }
        for (auto &i : mp){
            sort (i.second.begin(), i.second.end() ,[&](char i, char j){ return i>j;});
        }
        string ans = s;
        for (int i = 0; i<n; i++){
            int p = find(i);
            ans[i]=mp[p].back();
            mp[p].pop_back();
        }
        return ans;
    }
    int find(int u){
        if (parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }
    bool Union(int u, int v){
        int up = find(u);
        int vp = find(v);
        if (up==vp) return true;
        parent[up]=vp;
        return false;
    }
};