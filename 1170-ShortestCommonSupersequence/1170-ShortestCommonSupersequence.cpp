// Last updated: 16/02/2026, 11:56:52
class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int r = text1.size();
        int c = text2.size();
        //DP Creation
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

        //Path Tracing
        string ans;
        int i=r;
        int j=c;
        while(i>0 && j>0)
        {  
            //if same
            if (text1[i-1]==text2[j-1]){
                ans+=text1[i-1];
                i-=1;
                j-=1;
            }
            //different
            else{
                if (dp[i][j]==dp[i-1][j]){
                    ans+=text1[i-1];
                    i-=1;
                }
                else{
                    ans+=text2[j-1];
                    j-=1;                    
                }
            }
        }
        while (i>0){
            ans+=text1[i-1];
            i-=1;
        }
        while (j>0){
            ans+=text2[j-1];
            j-=1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};