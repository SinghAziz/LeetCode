// Last updated: 16/02/2026, 11:58:24
class Solution {
public:
    bool isMatch(string s, string p) {
        int length_s = s.size();
        int length_p = p.size();
        vector<vector<int>> dp(length_s + 1 , vector<int> (length_p+1, 0));
        dp[0][0] = true;
        for (int j = 1; j <= length_p; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }
        for(int i=1 ; i<=length_s; i++){
            for (int j=1 ; j<=length_p ; j++){
                if ((s[i-1]==p[j-1] || p[j-1]=='?')){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[length_s][length_p];
    }
};