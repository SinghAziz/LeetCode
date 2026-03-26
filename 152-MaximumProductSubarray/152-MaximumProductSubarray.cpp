// Last updated: 27/03/2026, 01:38:01
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int ans=nums[0];
        for (int i =1 ;i<n; i++){
            int current = nums[i];
            int temp_max=max({max_so_far*current, min_so_far*current, current});
            min_so_far = min({max_so_far*current, min_so_far*current, current});
            max_so_far = temp_max;
            ans = max(max_so_far, ans);
        }
        return ans;
    }
};