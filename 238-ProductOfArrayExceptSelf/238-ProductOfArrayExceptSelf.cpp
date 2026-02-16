// Last updated: 16/02/2026, 11:57:33
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Brute Force = product and divide
        int prod=1;
        int count=0;
        bool zero=false;
        for ( int i:nums){
            if (i){
                prod*=i;
            }
            if (!i){
                zero=true;
                count++;
            }
        }
        vector<int> ans;
        for ( int i:nums){
            if (i){
                if (!zero){
                    int val=prod/i;
                    ans.push_back(val);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                if ( count>1){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(prod);
                }
            }
        }
        return ans;
    }
};