// Last updated: 22/06/2026, 12:36:22
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for (auto i:beans) sum+=i;
        long long leftSum = 0;
        long long ans = LLONG_MAX;
        for (int i = 0 ;i<n; i++){
            long long curr = beans[i];
            long long rightSum = sum-leftSum-curr;
            long long steps = (
                abs(leftSum) //left
                 +
                abs(rightSum - (n-i-1)*curr) //right
            );
            leftSum += curr;
            ans = min(ans, steps);
        }
        return ans;
    }
};