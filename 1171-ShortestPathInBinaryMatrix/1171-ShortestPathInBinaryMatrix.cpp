// Last updated: 16/02/2026, 11:56:51
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        if (grid[0][0]){
            return -1;
        }
        q.push({{0,0}, 1});
        grid[0][0]=1;
        vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1,  0 ,1, 1, 1, 0,  -1, -1};
        while (!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int ans = q.front().second;
            q.pop();
            if(row == r-1 && col == c-1) return ans;
            for (int k=0; k<8;k++){
                int i = row + dx[k];
                int j = col + dy[k];
                if (i>=0 && j>=0 && i<r && j<c && grid[i][j]==0){
                    q.push({{i,j},ans+1});
                    grid[i][j]=1;
                }
            }
        }
        return -1;
    }
};