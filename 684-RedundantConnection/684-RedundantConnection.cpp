// Last updated: 16/02/2026, 11:57:10
class Solution {
public:
    vector<int> parent, rank;

    int find(int x){
        if (parent[x]!=x){
            parent[x]=find(parent[x]);//path compression
        }
        return parent[x];
    }

    bool unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if (px==py) return false; //cycle detected
        if (rank[px]>rank[py]) parent[py] = px;
        else if (rank[py] > rank[px]) parent[px] = py;
        else {
            parent[py] =px;
            rank[px]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size();
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        for (int i=1; i<=n;i++){
            parent[i]=i;
        }
        for (auto i:edges){
            if (!unite(i[0], i[1])) return i;
        }
        return {};
    }
};