// Last updated: 27/03/2026, 01:37:29
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp(n);
        int count = 0, sum = 0;
        for (int j=0 ; j<n; j++){
            sum+=nums[j];
            
            if (mp[sum-k]) count += mp[sum-k];
            if (sum==k)count++;
            mp[sum]++;
        }
        return count;
    }
};