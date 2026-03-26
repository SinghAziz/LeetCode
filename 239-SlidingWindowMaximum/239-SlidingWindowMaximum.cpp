// Last updated: 27/03/2026, 01:37:44
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        //Traversing the first window
        for (int i=0 ; i<k ; i++){
            while (!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        //Traversing the rest of the elements
        for (int i=k ; i<nums.size() ; i++){
            if (dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};