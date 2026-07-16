// Last updated: 16/07/2026, 12:29:55
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp (m, vector<int> (n, 0));
        for (int i = 0; i<n; i++) dp[0][i] = matrix[0][i];
        for (int i = 1; i<m; i++){
            for (int j = 0; j<n; j++){
                int top = dp[i-1][j];
                int leftd = j-1>=0 ? dp[i-1][j-1] : INT_MAX;
                int rightd = j+1<n ? dp[i-1][j+1] : INT_MAX;
                dp[i][j] = min({top, leftd, rightd}) + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i<n; i++) ans = min(ans, dp[m-1][i]);
        return ans;
    }
};