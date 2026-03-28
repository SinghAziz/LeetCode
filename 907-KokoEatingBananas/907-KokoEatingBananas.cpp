// Last updated: 28/03/2026, 15:28:37
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MIN;

        for (auto i: piles) right = max(right, i);

        while (left < right){
            int mid = left + (right - left) / 2;

            long long time_taken = 0;

            for (int i : piles){
                time_taken += i/mid + (i%mid != 0);
            }

            if (time_taken <= h) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};