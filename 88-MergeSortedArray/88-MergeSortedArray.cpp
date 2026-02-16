// Last updated: 16/02/2026, 11:58:10
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for ( int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        for ( int i=0;i<m+n;i++){
            cout<<nums1[i]<<" ";
        }
        for ( int i=0;i<m+n;i++){
            for ( int j=0;j<m+n;j++){
                if (nums1[i]<nums1[j]){
                    swap(nums1[i], nums1[j]);
                }
            }
        }
    }
};