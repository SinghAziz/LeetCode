// Last updated: 16/02/2026, 11:57:17
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& M) {
        int r = M.size();
        int c = M[0].size();
        int ans = 0;
        vector<vector<int>> grid(r+2, vector<int>(c+2,0));
        for (int i =0 ;i<r ;i++){
            for (int j=0;j<c;j++){
                grid[i+1][j+1] = M[i][j];
            }
        }

        for (int i=1 ; i<=r ; i++){
            for (int j=1; j<=c ; j++){
                if (grid[i][j]==1){
                    ans += 4 - (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1]);
                }
            }
        }
    return ans;
    }
};