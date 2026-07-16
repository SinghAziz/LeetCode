// Last updated: 16/07/2026, 12:30:10
class Solution {
public:
    int N;
    vector<int> memo;
    int climb(int n, vector<int>& cost){
        if (n>=N) return 0;
        if (memo[n]!=-1) return memo[n];
        memo[n] = min( climb(n+1, cost), 
                    climb(n+2, cost) 
                ) + cost[n];
        return memo[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        N = cost.size();
        memo = vector<int>(N, -1);
        cost.push_back(0);
        cost.push_back(0);
        return min(climb(1, cost), climb(0, cost));
    }
};