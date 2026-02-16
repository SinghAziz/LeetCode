// Last updated: 16/02/2026, 11:57:05
class Solution {
public:
    bool DFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,int j, int T){
        int n = grid.size();
        if (i<0 || j<0 || i>=n || j>=n || visited[i][j]==true || grid[i][j]>T ){
            return false;
        }
        if (i==n-1 && j==n-1){
            return true;
        }
        visited[i][j]=true;
        return (DFS (grid, visited, i+1, j, T) || 
                DFS (grid, visited, i-1, j, T) ||
                DFS (grid, visited, i, j+1, T) ||
                DFS (grid, visited, i, j-1, T));
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int high = n*n;
        int low = 0;

        while (low<high){
            int mid = (high+low)/2;
            vector<vector<bool>> visited(n*n,vector<bool>(n, false));
            if (DFS(grid, visited,0,0, mid)){
                high = mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};