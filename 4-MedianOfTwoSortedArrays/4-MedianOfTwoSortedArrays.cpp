// Last updated: 16/02/2026, 11:58:33
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto i: nums2){
            nums1.push_back(i);
        }
        sort(nums1.begin(), nums1.end());
        int l = nums1.size();
        double median;
        if (l%2!=0){
            median = nums1[(l/2)];
        }
        else{
            median = nums1[l/2] + nums1[(l-1)/2];
            median/=2;
        }
        return median;
    }
};