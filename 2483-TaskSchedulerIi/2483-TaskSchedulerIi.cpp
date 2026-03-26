// Last updated: 27/03/2026, 01:36:58
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> mp;
        long long days = 0;
        for (int i = 0 ; i<tasks.size() ; i++){
            int task = tasks[i];
            days++;
            if (mp.count(task) && days<= mp[task]+space){
                days = mp[task] + space + 1; 
            }
            mp[task]= days;
        }
        return days;
    }
};