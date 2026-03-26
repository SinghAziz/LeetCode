// Last updated: 27/03/2026, 01:39:45
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set (nums.begin(), nums.end());
        int longestStreak = 0;
        for (auto num : num_set){
            if (!num_set.count(num-1)){ // to check if num is start of a sequence 
                int currentElement = num;
                int currentStreak = 1;
                while (num_set.count(currentElement+1)){
                    currentElement+=1;
                    currentStreak+=1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};