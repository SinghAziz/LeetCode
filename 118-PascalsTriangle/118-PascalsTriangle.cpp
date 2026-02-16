// Last updated: 16/02/2026, 11:58:01
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector <int>> ans;
        vector <int> row;
        int n=numRows;
        if (n==1){
            row.push_back(1);
            ans.push_back(row);
            return ans;
        }

        if (n==2){
            row.push_back(1);
            ans.push_back(row);
            
            row.push_back(1);
            ans.push_back(row);
            return ans;
        }

        if (n>2){
            row.push_back(1);
            ans.push_back(row);

            row.push_back(1);
            ans.push_back(row);
            row.clear();
            for ( int i = 2; i<n; i++){
                row.push_back(1);
                for ( int j=1; j<i ; j++){
                    int sum=ans[i-1][j-1] + ans[i-1][j];
                    row.push_back(sum);
                }

                row.push_back(1);
                ans.push_back(row);
                row.clear();
            }
        }
    return ans;
    }
};