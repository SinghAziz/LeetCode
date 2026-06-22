// Last updated: 22/06/2026, 12:36:11
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> differenceArray(n+1, 0);
        for (auto q : queries){
            int l = q[0];
            int r = q[1];
            differenceArray[l]++;
            differenceArray[r+1]--;
        }
        for (int i = 1 ; i<=n; i++){
            differenceArray[i] += differenceArray[i-1];
        }
        for (int i = 0; i<n; i++){
            if (nums[i]) nums[i]-=differenceArray[i];
        }
        for (auto i : nums){
            if (i>0) return false;
        }
        return true;
    }
};