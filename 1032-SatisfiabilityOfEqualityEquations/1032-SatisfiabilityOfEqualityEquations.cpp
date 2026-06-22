// Last updated: 22/06/2026, 12:36:45
class Solution {
public:
    vector<int> parent = vector<int>(26);
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i<26 ; i++){
            parent[i] = i;
        }
        for (auto eq : equations){
            char sign = eq[1];
            int val1 = eq[0] - 'a';
            int val2 = eq[3] - 'a';
            if (sign=='='){
                Union(val1, val2);
            }
        }
        for (auto eq : equations){
            char sign = eq[1];
            int val1 = eq[0] - 'a';
            int val2 = eq[3] - 'a';
            if (sign=='!'){
                if (find(val1)==find(val2)) return false;
            }
        }
        return true;
    }

    void Union(int val1, int val2){
        int P1 = find(val1);
        int P2 = find(val2);
        if (P1!=P2) parent[P2] = P1;
    }

    int find(int val){
        if (val == parent[val]) return val;
        return find(parent[val]);
    }


};