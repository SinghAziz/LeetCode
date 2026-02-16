// Last updated: 16/02/2026, 11:57:28
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp (n, 1);
        int ans = 1;
        for (int i=1; i<n ;i++){
            for (int j=0; j<i; j++){
                if (arr[j]<arr[i]){
                    if (dp[j]+1>dp[i]){
                        dp[i]++;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};