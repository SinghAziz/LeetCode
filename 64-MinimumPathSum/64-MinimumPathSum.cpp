// Last updated: 16/02/2026, 11:58:20
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for (int i =0 ; i<r ; i++){
            for (int j = 0; j<c; j++){
                if (i==0 && j>0){
                    grid[i][j] += grid[i][j-1];
                }
                else if (i>0 && j==0){
                    grid[i][j] += grid[i-1][j];
                }
                else if (i>0 && j>0){
                    grid[i][j] = min(grid[i][j] + grid[i-1][j] , grid[i][j] + grid[i][j-1]);
                }
            }
        }
        return grid[r-1][c-1];
    }
};