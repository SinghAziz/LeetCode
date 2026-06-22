// Last updated: 22/06/2026, 12:36:31
class Solution {
public:
    vector<int> parent;
    int edges = 0;
    int makeConnected(int n, vector<vector<int>>& connections) {
        this->parent = vector<int>(n);
        for (int i = 0; i<n; i++){
            parent[i] = i;
        }
        for (auto nodes : connections){
            int x = nodes[0];
            int y = nodes[1];
            Union(x, y);
        }
        int alone = 0;
        for (int i = 0; i<n; i++){
            if (parent[i] == i) alone++;
        }
        return edges>=alone-1 ? alone-1 : -1;
    }
    void Union(int x, int y){
        int Px = find(x);
        int Py = find(y);
        if (Px==Py) edges++;
        parent[Py] = Px;
    }
    int find (int x){
        if (x == parent[x]) return x;
        return find(parent[x]);
    }
};