// Last updated: 16/02/2026, 11:57:41
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int x:nums){
            minHeap.push(x);
            if (minHeap.size()>k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};