// Last updated: 16/02/2026, 11:57:40
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // We will use unordered set
        unordered_set<int> seen;
        for (int i:nums){
            if (!seen.insert(i).second) return true;
        }
    return false;
    }
};