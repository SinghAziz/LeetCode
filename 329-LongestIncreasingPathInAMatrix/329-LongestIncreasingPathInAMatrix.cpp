// Last updated: 16/02/2026, 11:57:26
class Solution {
public:
    int DFS(vector<vector<int>>& grid, int i,int j, int m, int n, vector<vector<int>>& M, int prev){
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j]<=prev){
            return 0;
        }
        if (M[i][j]!=0){
            return M[i][j];
        }
        prev = grid[i][j];
        M[i][j] = 1 + max({ DFS (grid, i+1, j, m, n, M, prev) ,
        DFS (grid, i-1, j, m, n, M, prev) ,
        DFS (grid, i, j+1, m, n, M, prev) ,
        DFS (grid, i, j-1, m, n, M, prev )});
    return M[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> M(m, vector<int>(n, 0));
        for (int i=0 ; i<m ; i++){
            for (int j = 0; j<n ;j++){
                ans = max(ans, DFS(grid, i, j ,m, n, M, -1));
            }
        }
    return ans;
    }
};