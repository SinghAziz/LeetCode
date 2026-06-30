// Last updated: 30/06/2026, 14:06:21
1
2
3class Solution {
4public:
5
6    int maximumStrongPairXor(vector<int>& nums) {
7     int ans=0;
8        
9        
10        for (int i = 0; i<nums.size(); i++){
11           
12            for (int j = i; j<nums.size(); j++){
13                if ( abs (nums[j]-nums[i]) <= min(nums[j] , nums[i]) )
14                {
15                        int temp= nums[i]^nums[j];
16                    ans=max(ans,temp);
17            }
18                }
19                    
20        }
21        return ans;
22    }
23};