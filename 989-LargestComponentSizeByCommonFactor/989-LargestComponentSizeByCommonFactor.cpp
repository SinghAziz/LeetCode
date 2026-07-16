// Last updated: 16/07/2026, 12:29:53
class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxE = *max_element(nums.begin(), nums.end());
        parent = vector<int>(maxE+1);
        size = vector<int> (maxE+1, 0);
        for (int i = 0; i<=maxE; i++){
            parent[i] = i;
        }
        for (int i = 0; i<n; i++){
            size[nums[i]]++;
        }
        for (int i = 0; i<n; i++){
            for (int j = 2; j*j<=nums[i]; j++){
                if (nums[i]%j==0){ Union(j, nums[i]);
                if (nums[i]/j!=j) Union(nums[i], nums[i]/j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i<n; i++){
            int parent = find(nums[i]);
            ans = max(size[parent], ans);
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
        if (size[up]>size[vp]){
            parent[vp] = up;
            size[up] += size[vp];
        }
        else{
            parent[up] = vp;
            size[vp] += size[up];
        }
        return false;
    }
};