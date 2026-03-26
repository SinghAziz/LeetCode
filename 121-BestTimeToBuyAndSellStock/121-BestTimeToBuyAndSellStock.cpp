// Last updated: 27/03/2026, 01:39:48
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minValue = INT_MAX;
        for (auto i:prices){
            minValue = min(minValue, i);
            maxProfit = max(maxProfit, i-minValue);
        }
        return maxProfit;
    }
};