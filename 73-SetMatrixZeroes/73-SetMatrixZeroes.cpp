// Last updated: 16/02/2026, 11:58:16
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector <pair<int,int>> zeroes={};

    //checking zeroes using traversing
    for ( int i=0; i<rows; i++){
        for ( int j=0 ; j<cols ; j++){
            //Check zero
            if (matrix[i][j]==0){
                zeroes.push_back({i, j});
            }
        }
    }

    //Traversing through zeroe elements
    for (int y=0;y<zeroes.size();y++){
        int rows1=zeroes[y].first;
        int cols1=zeroes[y].second;
        //Making rows zero
            for ( int k=0;k<rows;k++){
                matrix[k][cols1]=0;
            }
        //Making cols zero
            for(int h=0;h<cols;h++){
                matrix[rows1][h]=0;
            }
    }
    }
};