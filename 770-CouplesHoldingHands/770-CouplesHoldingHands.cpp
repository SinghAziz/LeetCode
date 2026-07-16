// Last updated: 16/07/2026, 12:30:08
class Solution {
public:
    vector<int> parent;
    int swaps = 0;
    int minSwapsCouples(vector<int>& row) {
        parent = vector<int> (2*row.size()+1);
        for (int i = 0; i<=2*row.size(); i++){
            if (i%2) parent[i] = i-1;
            else parent[i] = i;
        }
        for (int i : parent){
            cout<<i<<" ";
        }
        for (int i = 0 ;i<row.size()-1; i+=2){
            int u = row[i];
            int v = row[i+1];
            Union(u, v);
        }
        return swaps;
    }
    int find(int u){
        if (parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }
    bool Union(int u, int v){
        int up = find(u);
        int vp = find(v);
        if (up==vp) return true;
        swaps++;
        parent[up] = vp;
        return false;
    }
};