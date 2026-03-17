// Last updated: 18/03/2026, 01:25:12
1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n = nums.size();
5        int i = 0;
6        while(i<n){
7            if (nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
8            else i++;
9        }
10        for (int i=0 ; i<n ; i++){
11            if (nums[i]!=i+1) return i+1;
12        }
13        return n+1;
14    }
15};