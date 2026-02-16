// Last updated: 16/02/2026, 11:56:55
class Solution {
public:

    bool canShip(vector<int>& weights, int days, int capacity){
        int d = 1;
        int sum = 0;
        for (int i = 0;i<weights.size();i++){
            if (sum+weights[i] > capacity){
                d++;
                sum = 0;
            }
            sum+=weights[i];
        }
        return d<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        for (int i: weights){
            low = max(low, i);
            high+=i;
        }
        int ans;
        while (low<=high){
            int mid = low + (high-low)/2;
            if (canShip(weights, days, mid)){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
    return ans;
    }
};