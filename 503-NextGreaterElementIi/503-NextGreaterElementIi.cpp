// Last updated: 30/04/2026, 19:58:12
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> answer(nums.size());
        for (int i = 2*nums.size()-1 ; i>=0 ; --i){
            while (st.size() && nums[st.top()]<= nums[i%nums.size()]){
                st.pop();
            }
            answer[i%nums.size()] = st.size()>0 ? nums[st.top()] : -1;
            st.push(i%nums.size());
        }
        return answer;
    }
};