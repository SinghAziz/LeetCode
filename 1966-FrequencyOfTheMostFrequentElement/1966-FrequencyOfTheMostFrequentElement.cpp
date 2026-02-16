// Last updated: 16/02/2026, 11:56:44
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long curr=0;
        int left=0;
        int ans=0;
        for (int right=0;right<nums.size();right++){
            long target= nums[right];
            curr+=target;

            while ( (right-left+1)*target -curr >k ){
                curr-=nums[left];
                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};