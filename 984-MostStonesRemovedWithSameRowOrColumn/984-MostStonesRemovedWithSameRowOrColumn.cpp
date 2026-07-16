// Last updated: 16/07/2026, 12:29:54
class Solution {
public:
    vector<int> parent;
    vector<int> rows;
    vector<int> cols;
    int components = 0;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        rows = vector<int>(10001, -1);
        cols = vector<int>(10001, -1);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++) {
            int u = stones[i][0];
            int v = stones[i][1];
            if (rows[u] != -1) {
                Union(rows[u], i);
                // rows[u] = i;
            }
            if (cols[v] != -1) {
                Union(cols[v], i);
                // cols[v] = i;
            }
            if (rows[u]==-1)rows[u] = i;
            if (cols[v]==-1)cols[v] = i;
        }
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i)
                components++;
        }
        return n - components;
    }
    int find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    bool Union(int u, int v) {
        int up = find(u);
        int vp = find(v);
        if (up == vp)
            return true;
        parent[up] = vp;
        return false;
    }
};