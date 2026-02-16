// Last updated: 16/02/2026, 11:58:34
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> final;
        for (int i=0;i<nums.size();i++){
            for (int j=1; j<nums.size();j++){
                if (nums[i]+nums[j]==target && i!=j){
                    final.push_back(i);
                    final.push_back(j);
                    return final;
                }   
            }
        }
        return final;
    }
};