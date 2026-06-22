// Last updated: 22/06/2026, 12:36:18
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> decreasing(n,1); //left to right
        vector<int> increasing(n,1); //right to left
        vector<int> ans;
        for (int i = 1; i<n; i++){
            if (nums[i]<=nums[i-1])
                decreasing[i] = decreasing[i-1]+1;
        }
        for (int i = n-2; i>=0 ; i--){
            if (nums[i]<=nums[i+1]) 
                increasing[i] = increasing[i+1]+1;
        }
        for (int i = 1; i<n-1; i++){
            if (decreasing[i-1]>=k && increasing[i+1]>=k)
                ans.push_back(i);
        }
        return ans;
    }
};