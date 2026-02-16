// Last updated: 16/02/2026, 11:57:07
class Solution {
public:
    int findLength(vector<int>& text1, vector<int>& text2) {
        int r = text1.size();
        int c = text2.size();
        vector<vector<int>> dp(r+1, vector<int> (c+1,0));
        int ans = 0;
        for (int i = 0 ; i<r ; i++){
            for (int j = 0 ; j<c ; j++){
                //same
                if (text1[i]==text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1 ;
                }
                //different
                else{
                    dp[i+1][j+1] = 0;
                }
                ans = max(ans, dp[i+1][j+1]);
            }
        }
        return ans;
    }
};