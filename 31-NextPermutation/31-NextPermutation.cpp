// Last updated: 16/02/2026, 11:58:26
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int pivot = -1;

        //Find the first decreasing element from the right - pivot
        for ( int i=n-2;i>=0;i--){
            if (nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }

        //Step 2: If no pivot found, i.e. pivot == -1
        if (pivot==-1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //Find rightmost element greater than pivot 
        for(int i=n-1;i>pivot;i--){
            if (nums[i]>nums[pivot]){
                swap(nums[pivot], nums[i]);
                break;
            }
        }

        //Reversing the right side
        reverse(nums.begin()+pivot+1, nums.end());
    }
};