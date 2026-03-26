// Last updated: 27/03/2026, 01:37:14
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0, count = 0, left=0, zeroes=k;
        for (int right = 0 ;right<n ;right++){
            if (nums[right]==1) count++;
            else if ( nums[right] == 0 && zeroes>0){
                    count++;
                    zeroes--;
                }
            else if (nums[right]==0 && zeroes==0){
                    zeroes=k;
                    count = 0;
                    left++;
                    right = left-1;
                }
            ans = max(ans, count);
            }
        return ans;
        }
    };