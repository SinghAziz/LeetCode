// Last updated: 16/02/2026, 11:58:17
class Solution {
public:
    int minDistance(string word1, string word2) {
        int r = word1.size();
        int c = word2.size();
        vector<vector<int>> dp(r+1, vector<int> (c+1, 0));

        //Initialization
        for (int i=0 ; i<=r ; i++)
        {
            dp[i][0] = i;
        }
        for (int j=0 ; j<=c ; j++)
        {
            dp[0][j] = j;
        }
        //Filling up the dp
        for (int i = 1 ; i<=r ; i++){
            for(int j= 1; j<=c; j++){
                //different
                if (word1[i-1]!=word2[j-1]){
                    dp[i][j] = 1 + min( {dp[i-1][j], dp[i][j-1], dp[i-1][j-1] } );
                }
                //same
                else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[r][c];
    }
};