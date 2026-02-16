// Last updated: 16/02/2026, 11:57:42
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1){
            return nums[0];
        }
        int dp [n];
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        
        for ( int i = 2 ; i<n-1 ; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        //return dp[n-2];
        int dp2 [n];
        dp2[0]=0;
        dp2[1] = nums[1];

        for ( int i = 2 ; i<n ; i++){
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i]);
        }
        //return dp[n-1];
        int ans = max(dp[n-2], dp2[n-1]);
        return ans;
    }
};