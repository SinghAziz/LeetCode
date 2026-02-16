// Last updated: 16/02/2026, 11:57:21
class Solution {
public:
    void DFS(int i, int j, vector<vector<bool>>& visited, int prevHeight, vector<vector<int>>& heights){
        int r = heights.size();
        int c = heights[0].size();
        if (i<0 || j<0 || i>=r || j>=c || visited[i][j]==true || prevHeight>heights[i][j]){
            return;
        }
        visited[i][j] = true;
        DFS(i+1, j, visited, heights[i][j], heights);
        DFS(i-1, j, visited, heights[i][j], heights);
        DFS(i, j+1, visited, heights[i][j], heights);
        DFS(i, j-1, visited, heights[i][j], heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> atl (r, vector<bool> (c, false));
        vector<vector<bool>> pac (r, vector<bool> (c, false));

        for (int i= 0 ;i < c; i++){
            DFS(r-1,i, atl, heights[r-1][i], heights);
            DFS(0, i, pac, heights[0][i], heights);
        }
        for (int j= 0 ; j<r;j++){
            DFS(j, 0, pac, heights[j][0], heights);
            DFS(j, c-1, atl, heights[j][c-1], heights);
        }

        vector<vector<int>> ans;
        for (int i= 0; i <r ;i++){
            for (int j =0; j<c ;j++){
                // cout<<"i: "<<i<<" j: "<<j<<endl;
                // cout<<"alt: "<<atl[i][j]<<endl;
                // cout<<"pac: "<<pac[i][j]<<endl;
                if (atl[i][j] == true && pac[i][j]==true){
                    ans.push_back( {i, j});
                }
            }
        }
    return ans;
    }
};