// Last updated: 16/02/2026, 11:57:20
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates; // Vector to store the duplicates
        
        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Get the index corresponding to the current element's value
            int index = abs(nums[i]) - 1;
            
            // If the value at this index is negative, it means the number has been seen before
            if (nums[index] < 0) {
                duplicates.push_back(abs(nums[i]));
            } else {
                // Otherwise, negate the value at this index to mark it as seen
                nums[index] = -nums[index];
            }
        }
        
        // Return the vector containing all duplicates
        return duplicates;
    }
};
