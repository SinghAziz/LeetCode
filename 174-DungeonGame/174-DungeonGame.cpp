// Last updated: 16/02/2026, 11:57:50
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();

        //checking the right corner
        dungeon[r-1][c-1] = max(1,1-dungeon[r-1][c-1]);

        //right column
        for(int i=r-2 ; i>=0; i--){
            dungeon[i][c-1] = max (1, dungeon[i+1][c-1]-dungeon[i][c-1]);
        }

        //bottom row
        for (int j=c-2 ; j>=0; j--){
            dungeon[r-1][j] = max(1, dungeon[r-1][j+1] - dungeon[r-1][j]);
        }

        //rest of the elements
        for(int i = r-2; i>=0; i--){
            for (int j = c-2; j>=0; j--){
                dungeon[i][j] = max( 1, min(dungeon[i+1][j], dungeon[i][j+1]) - dungeon[i][j]);
            }
        }
        return dungeon[0][0];
    }
};