// Last updated: 16/02/2026, 11:57:57
class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& board){
        int r = board.size();
        int c = board[0].size();
        if (i<0 || j<0 || i>=r || j>=c || board[i][j]!='O') return;
        board[i][j] = '#';
        DFS(i+1, j, board);
        DFS(i-1, j, board);
        DFS(i, j+1, board);
        DFS(i, j-1, board);
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for (int i =0 ; i<r ;i++){
            if (board[i][0]=='O') DFS(i, 0, board);
            if (board[i][c-1]=='O') DFS(i, c-1, board);
        }
        for (int j=0;j<c;j++){
            if (board[0][j]=='O') DFS(0, j, board);
            if (board[r-1][j]=='O') DFS(r-1, j, board);
        }

        for (int i =0 ;i <r ;i++){
            for (int j = 0 ;j<c ;j++){
                if (board[i][j]=='O') board[i][j]='X';
                if (board[i][j]=='#') board[i][j]='O';
        }
    }
}
};