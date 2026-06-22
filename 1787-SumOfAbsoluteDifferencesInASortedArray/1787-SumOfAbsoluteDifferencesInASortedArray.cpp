// Last updated: 22/06/2026, 12:36:29
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> ans;
        for (auto i : nums) sum+=i;
        int left_sum = 0;
        for (int i = 0; i<n ;i++){
            int curr = nums[i];
            int right_sum = sum-left_sum-curr;
            
            ans.push_back(
                 
                abs ((right_sum - (curr * (n-i-1))))  
                            + 
                abs ((left_sum - (curr * i))) 

                );
            left_sum += curr;
        }
        return ans;
    }
};