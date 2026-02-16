// Last updated: 16/02/2026, 11:58:15
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low  = -1;
        int mid = 0;
        int high = arr.size()-1;

        while (mid<=high){
            if (arr[mid]==0) swap(arr[++low], arr[mid++]);
            else if (arr[mid]==2) swap(arr[mid], arr[high--]);
            else mid++;
        }
    }
};