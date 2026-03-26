// Last updated: 27/03/2026, 01:38:05
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_gain = 0, total_gain = 0, answer = 0;
        for (int i = 0; i<gas.size() ; i++){
            total_gain += gas[i]-cost[i];
            curr_gain += gas[i]-cost[i];
            if (curr_gain<0) {
                answer=i+1;
                curr_gain = 0;
            }
        }
        return total_gain<0 ? -1 : answer;
    }
};