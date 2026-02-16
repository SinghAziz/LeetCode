// Last updated: 16/02/2026, 11:56:40
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int left = 0;
        int length = 0;
        sort(nums.begin(), nums.end());
        for (int right = 0 ; right<nums.size();right++){
            if ( (long long)nums[right] > (long long)nums[left]*k){
                left++;
            }
            length = max(length, right-left+1);
        }
        return nums.size() - length;
    }
};