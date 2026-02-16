// Last updated: 16/02/2026, 11:57:54
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for( int x:nums){
            ans=ans^x;
        }
        return ans;
    }
};