// Last updated: 27/03/2026, 01:39:47
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int start_price = prices[0];
        for (int i = 1 ; i<n ;i++){
            if (prices[i]>start_price) ans += prices[i]-start_price;
            start_price = prices[i];
        }
        return ans;
    }
};