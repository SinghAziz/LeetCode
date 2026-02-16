// Last updated: 16/02/2026, 11:57:14
class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        int r = text1.size();
        string text2 = text1;
        reverse(text2.begin(), text2.end());
        int c = text2.size();
        vector<vector<int>> dp(r+1, vector<int> (c+1,0));

        for (int i = 0 ; i<r ; i++){
            for (int j = 0 ; j<c ; j++){
                //same
                if (text1[i]==text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1 ;
                }
                //different
                else{
                    dp[i+1][j+1] = max (dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[r][c];
    }
};