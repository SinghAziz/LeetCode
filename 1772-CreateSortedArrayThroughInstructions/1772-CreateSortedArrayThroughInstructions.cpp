// Last updated: 16/07/2026, 12:29:33
unordered_map<int, int> mp;
int MOD = 1000000007;
class NumArray{
    public:
    vector<int> tree;
    int n;
    NumArray(int n){
        this->n = n;
        tree.resize(4*n, 0);
    }
    int find(int val){
        int pos = mp[val];
        int small = query(pos, 0, n-1, 0, pos-1, 0);
        int big = query(pos, 0, n-1, pos+1, n-1, 0);
        update(pos, 0, n-1, 0);
        return min(small, big);
    }
    void update(int pos, int tl, int tr, int index){
        if (tl>pos || tr<pos) return; //Base case
        if (tl==tr){ //found
            tree[index]++;
            return;
        }
        int mid = (tl+tr)>>1;
        update(pos, tl, mid, 2*index+1); //left
        update(pos, mid+1, tr, 2*index+2); //right
        tree[index] = (tree[2*index+1] + tree[2*index+2]);
    }
    int query(int pos, int tl, int tr, int ql, int qr, int index){
        //no overlap
        if (qr<tl || tr<ql) return 0;
        // full overlap
        if (tl>=ql && tr<=qr) return tree[index];
        //partial overlap
        int mid = (tl+tr)>>1;
        return query(pos, tl, mid, ql, qr, 2*index+1) + 
            query(pos, mid+1, tr, ql, qr, 2*index+2);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        vector<int> sorted = instructions;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int n = sorted.size();
        NumArray* root = new NumArray(n);
        for (int i = 0; i<sorted.size(); i++) mp[sorted[i]] = i;
        int ans = 0;
        for (int i = 0; i<instructions.size(); i++){
            ans = ans % MOD+ root->find(instructions[i])  % MOD ;
        }
        return ans;
    }
};