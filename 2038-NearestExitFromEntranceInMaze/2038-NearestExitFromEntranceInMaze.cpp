// Last updated: 16/02/2026, 11:56:38
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();
        queue<pair<int, int>> q;
        int ans = 0;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]]= '+';
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        while(!q.empty()){
            int size=q.size();
            while (size--){
            int tempx = q.front().first;
            int tempy = q.front().second;
            q.pop();
                if (ans!=0){
                    if (tempx==0 || tempy==0 || tempx==r-1 || tempy==c-1) return ans;
                }
            
                for (int k =0 ;k<4;k++){
                    int i = tempx+dx[k];
                    int j = tempy+dy[k];
                    if (i>=0 &&  i<r && j>=0 && j<c && maze[i][j]=='.'){
                        q.push({i,j});
                        maze[i][j]='+';
                    }
                }
            }
            ans++;
        }
        return -1;
    }    
};