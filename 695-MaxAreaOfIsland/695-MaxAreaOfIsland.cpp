// Last updated: 16/02/2026, 11:57:09
class Solution {
public:

    int DFS(vector<vector<int>>& grid, int i, int j, int r, int c){
        if (i<0 || j<0 || i>=r || j>=c || grid[i][j]==0){
            return 0;
        }
        int area = 1;
        grid[i][j]=0;
        area += DFS(grid, i+1, j, r, c);
        area += DFS(grid, i, j-1, r, c);
        area += DFS(grid, i, j+1, r, c);
        area += DFS(grid, i-1, j, r, c);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int area = 0;
        for (int i = 0 ; i<r; i++){
            for (int j=0 ; j<c; j++){
                area = max (DFS(grid, i, j, r, c), area);
            }
        }
        return area;
    }
};