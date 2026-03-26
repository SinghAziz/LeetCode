// Last updated: 27/03/2026, 01:37:00
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int smallest=INT_MAX, largest=INT_MIN;
        int small_index, large_index;
        int swaps = 0;
        for (int i =0 ; i<nums.size();i++){
            if (nums[i]<smallest) small_index = i;
            smallest = min(smallest, nums[i]);
            if (nums[i]>=largest) large_index = i;
            largest = max (largest, nums[i]);
        }
        if (large_index<small_index) large_index++;
        while (small_index!=0 && small_index>0){
            swap(nums[small_index], nums[small_index-1]);
            small_index--;
            swaps++;
        }
        while (large_index!=nums.size()-1 && large_index < nums.size()-1){
            swap(nums[large_index], nums[large_index+1]);
            large_index++;
            swaps++;
        }
        return swaps;
    }
};