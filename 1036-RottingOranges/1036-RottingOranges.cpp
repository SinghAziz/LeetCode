// Last updated: 16/02/2026, 11:56:57
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue< pair<int,int>> q;
        int fresh=0;
        for (int i = 0 ; i < r; i++){
            for (int j = 0 ; j<c ; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
                if (grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if (fresh==0){
            return 0;
        }
        int level = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (q.size()){
            int s = q.size();
            for (int k = 0 ; k<s ; k++){
                auto [tempx, tempy] = q.front();
                q.pop();
                for (int i = 0 ; i < 4 ; i++){
                    int newx = tempx + dx[i];
                    int newy = tempy + dy[i];
                if (newx<0 || newy<0 || newx>=r ||newy>=c || grid[newx][newy]==0 || grid[newx][newy]==2){
                    continue;
                }
                grid[newx][newy] = 2;
                fresh--;
                q.push({newx, newy});
                }
            }
            level++;
        }
        if (fresh){
            return -1;
        }
        return --level;
    }
};