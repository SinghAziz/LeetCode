// Last updated: 16/02/2026, 11:57:06
class Solution {
public:
    void DFS(vector<vector<int>>& image, int i, int j, int color, int r, int c, int prev){
        if (i<0 || j<0 || i>=r || j>=c || image[i][j]==color || image[i][j]!=prev ){
            return;
        }
        image[i][j] = color;
        DFS(image, i+1, j, color,  r, c, prev);
        DFS(image, i-1, j, color,  r, c, prev);
        DFS(image, i, j+1, color,  r, c, prev);
        DFS(image, i, j-1, color,  r, c, prev);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        int prev = image[sr][sc];
        // image[sr][sc] = color;
        DFS(image,sr, sc, color, r, c, prev);
        return image;
    }
};