// Last updated: 27/03/2026, 01:39:58
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lasPos = nums.size() -1;
        for (int i = nums.size()-1 ; i>=0 ; i--){
            if (i+nums[i] >= lasPos){
                lasPos = i;
            }
        }
        return lasPos == 0;
    }
};