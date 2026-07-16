// Last updated: 16/07/2026, 12:29:35
class Solution {
public:
    vector<int> houses;
    vector<vector<int>> cost;
    vector<vector<vector<int>>> dp;
    int m, n, target;
    int solve(int i, int pcolor, int comp){
        if (comp>target) return 1e9;
        if (i == m) 
            return (comp==target) ? 0 : 1e9; 
        if (dp[i][pcolor][comp]!=-1) return dp[i][pcolor][comp];
        if (houses[i] != 0){
            return houses[i] == pcolor ? solve(i+1, houses[i], comp) : 
                                        solve(i+1, houses[i], comp+1);
        }
        int answer = 1e9;
        for (int index = 0; index<cost[i].size(); index++){
            answer = min(
                answer, 
                solve(i+1, index+1, index+1!=pcolor ? comp+1 : comp) + cost[i][index]
                );
        }
        return dp[i][pcolor][comp] = answer;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->m = m;
        this->n = n;
        this->target = target;
        this->houses = houses;
        this->cost = cost;
        this->dp = vector<vector<vector<int>>> (m+1, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
        int ans = solve(0, 0, 0);
        return ans == 1e9 ? -1: ans;
    }
};