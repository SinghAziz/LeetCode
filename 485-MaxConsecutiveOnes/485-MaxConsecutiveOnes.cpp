// Last updated: 16/02/2026, 11:57:16

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size=nums.size();
        int i=0;
        int maxi=0;
        while(i<size){
            int sum=0;
            while (i<size && nums[i]!=0){
                sum+=1;
                i++;
            }
            maxi=max(maxi,sum);
            i++;
        }
        return maxi;
    }
};