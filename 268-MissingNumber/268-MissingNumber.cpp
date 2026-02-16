// Last updated: 16/02/2026, 11:57:30
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int size=nums.size();
        // vector <int> arr(size,0);
        // for( int i=0;i<nums.size();i++){
        //     int j=nums[i];
        //     if (j>=0 && j<size){
        //         arr[j]=1;
        //     }
        // }
        // for ( int i=0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        // for (int i=0;i<nums.size();i++){
        //     if (arr[i]==0){
        //         return i;
        //     }
        // }
        // return arr.size();
        int nsum;
        int sum=0;
        int diff;
        int size=nums.size();
        nsum=size*(size+1)/2;
        for ( int i=0;i<size;i++){
            sum+=nums[i];
        }
        diff=nsum-sum;
        return diff;
    }
};