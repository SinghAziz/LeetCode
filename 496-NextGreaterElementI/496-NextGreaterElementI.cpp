// Last updated: 30/04/2026, 19:58:13
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        
        unordered_map<int, int> mp;
        for (int i = 0 ; i<nums1.size() ;i++) mp[nums1[i]] = i;

        vector<int> ans (nums1.size(), -1);
        for (int i = 0 ; i<nums2.size() ; i++){
            int curr = nums2[i];
            while (st.size() && curr>st.top()){
                ans[mp[st.top()]] = curr;
                st.pop();
            }
            if (mp.find(curr)!=mp.end()) st.push(curr);
        }
        return ans;
    }
};