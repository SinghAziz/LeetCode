// Last updated: 16/02/2026, 11:58:28
class Solution {
public:
    void solve(int n, int open, int close, string& curr, vector<string>& res){

        if ( curr.size() == n*2){
            res.push_back(curr);
        }
        if (open<n){
            curr.push_back('(');
            solve(n, open+1, close, curr, res);
            curr.pop_back();
        }
        if ( close < open){
            curr.push_back(')');
            solve(n, open, close+1, curr, res);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        vector<string> res;
        int open = 0;
        int close = 0;
        solve (n, open, close, curr, res);
        return res;
    }


};