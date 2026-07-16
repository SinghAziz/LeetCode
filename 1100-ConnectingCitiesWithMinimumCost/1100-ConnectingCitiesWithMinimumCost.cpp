// Last updated: 16/07/2026, 12:29:46
class Solution {
public:
    vector<int> parent;
    int cost = 0, edges = 0;
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](vector<int>&a, vector<int>&b){return a[2]<b[2];});
        parent = vector<int> (n+1);
        for (int i = 0; i<=n; i++) parent[i]=i;
        for (int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            int w = connections[i][2];
            if (!Union(u, v)){
                cost+=w;
            }
        }
        return cost==0 || edges<n-1?-1:cost;
    }
    int find(int u){
        if (parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }
    bool Union(int u, int v){
        int up = find(u);
        int vp = find(v);
        if (up == vp) return true;
        edges++;
        parent[up] = vp;
        return false;
    }
};