// Last updated: 16/02/2026, 11:57:27
class Solution {
public:
    int coinChange(vector<int>& val, int W) {
        const int INF = W+1; //cause it can never be reached
        // if (!W){
        //     return 0;
        // }
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0 ));
        for (int k=0 ; k<=n ; k++){
            dp[k][0]=0;
        }
        for (int k=0 ; k<=W ; k++){
            dp[0][k]=INF;
        }
        for ( int i=1; i<=n ; i++){
            for (int j=1; j<=W; j++){
                dp[i][j] = dp [i-1][j];
                if (j>=val[i-1]){
                    dp[i][j] = min(dp [i][j] , dp[i][j-val[i-1]]+1);
                    }
                }
            }
        return (dp[n][W]==INF?-1:dp[n][W]);
    }
};