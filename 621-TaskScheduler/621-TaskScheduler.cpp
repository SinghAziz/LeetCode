// Last updated: 27/03/2026, 01:37:28
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int maximum=0, maxCount=0;
        for (auto i : tasks){
            mp[i]++;
            if (mp[i]==maximum){
                maxCount++;
            }
            else if (mp[i]>maximum){
                maxCount = 1;
                maximum = mp[i];
            }
        }
        int emptySlots = (n-(maxCount-1))*(maximum-1);
        int availableTasks = tasks.size() - (maximum*maxCount);
        int idles = max(0 , emptySlots - availableTasks);
        return idles + tasks.size();
    }
};