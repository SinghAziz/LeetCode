// Last updated: 16/07/2026, 12:29:21
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (abs(nums[j] - nums[i]) <= min(nums[j], nums[i])) {
                    int temp = nums[i] ^ nums[j];
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};