// Last updated: 16/02/2026, 11:58:13
class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void dfs(int i, vector<int>& nums) {
        if (i == nums.size()) {      // reached end
            res.push_back(curr);     // store current subset
            return;
        }
        // 1) skip nums[i]
        dfs(i+1, nums);

        // 2) take nums[i]
        curr.push_back(nums[i]);
        dfs(i+1, nums);
        curr.pop_back();             // undo take (backtrack)
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};
