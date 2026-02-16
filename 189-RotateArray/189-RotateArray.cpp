// Last updated: 16/02/2026, 11:57:49
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> ans=nums;
        int size=nums.size();
        int i=0;
        
        while (size){
            int j=(i+k)%(nums.size()); 
            ans[j]=nums[i];
            i++;   
            size--;
        }
        nums=ans;
    }
};