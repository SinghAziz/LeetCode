// Last updated: 22/06/2026, 12:36:36
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0);
        for (auto q : bookings){
            int l = q[0];
            int r = q[1];
            int val = q[2];
            diff[l] += val;
            diff[r+1] -= val;
        }
        for (int i = 2 ; i<=n+1; i++){
            diff[i] += diff[i-1];
        }
        return vector<int>(diff.begin()+1, diff.begin()+n+1);
    }
};