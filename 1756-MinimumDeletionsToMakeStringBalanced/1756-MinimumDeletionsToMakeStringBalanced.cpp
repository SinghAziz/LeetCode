// Last updated: 16/02/2026, 11:56:45
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        int count = 0;
        int ans=0;
        if (s[0]=='b') count++;
        for (int i = 1 ;i < n ;i++){
            if (s[i]=='b'){
                count++;
            }
            if (s[i]=='a'){
                dp[i] = min(dp[i-1]+1, count);
                // ans = max(ans, dp[i]);
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
    }
};