// Last updated: 16/02/2026, 11:57:52
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        while (low<high){
            mid = low + (high-low)/2; 
            if (nums[mid] > nums[n-1]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};