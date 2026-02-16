// Last updated: 16/02/2026, 11:57:13
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0 ; i < r;i++){
            for (int j =0 ; j < c ;j++){
                if (mat[i][j]!=0){
                    mat[i][j] = -1; 
                }
                else{
                    q.push({i,j});
                }
            }
        }
        vector<int> dx={1, -1, 0, 0};
        vector<int> dy={0, 0, 1,-1};
        while (q.size()>0){
            pair<int, int> temp = q.front();
            q.pop();
            for (int k=0; k<4;k++){
                int tempx = temp.first+dx[k];
                int tempy = temp.second+dy[k];
                if (tempx>=0 && tempy>=0 && tempx<r && tempy<c && mat[tempx][tempy]==-1){
                    q.push({tempx, tempy});
                    mat[tempx][tempy]=1+mat[temp.first][temp.second];
                }
            }
            }
        return mat;
    }
};