// Last updated: 16/02/2026, 11:57:29
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();

        for ( int i =0;i<size;i++){
            for (int j=0;j<size-1;j++){
                if(nums[j]==0){
                swap(nums[j], nums[j+1]);
            }
            }
        }
    }
};