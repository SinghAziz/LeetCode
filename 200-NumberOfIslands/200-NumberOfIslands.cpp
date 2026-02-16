// Last updated: 16/02/2026, 11:57:47
class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        if (i<0 || j<0 || i>=r || j>=c || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        DFS(i-1, j, grid);
        DFS(i+1, j, grid);
        DFS(i, j+1, grid);
        DFS(i, j-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int sunken = 0;
        for (int i = 0 ; i<r ;i++){
            for (int j = 0; j<c; j++){
                if (grid[i][j]=='1'){
                    DFS(i, j, grid);
                    sunken++;
                }
            }
        }
        return sunken;
    }
};