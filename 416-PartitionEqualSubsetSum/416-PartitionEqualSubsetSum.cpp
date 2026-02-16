// Last updated: 16/02/2026, 11:57:22
class Solution {
public:
    bool canPartition(vector<int>& val) {
        //calculating the sum
        int sum = 0;
        int n = val.size();
        for ( int i =0 ; i<n ; i++){
            sum += val[i];
        }
        
        if (sum%2){
            return false;
        }

        int W=sum/2;
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

        for (int k=0;k<n+1;k++){
            dp[k][0]=1;
        }

        for ( int i=1; i<=n ; i++){
            for (int j=0; j<=W; j++){
                if (j>=val[i-1]){
                    dp[i][j] = dp [i-1][j] + dp[i-1][j-val[i-1]] % 10000009;
                }
                else{
                    dp[i][j] = dp [i-1][j];
                }
            }
        }
        if (dp[n][W]>=1){
            return true;
        }
        return false;
    }
};