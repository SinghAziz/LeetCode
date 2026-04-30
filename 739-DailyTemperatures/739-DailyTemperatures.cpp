// Last updated: 30/04/2026, 19:58:02
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> arr(n, 0);
        stack<int> st;
        for (int i = 0 ; i<n ;i++){
            if (st.size()) {
                int prevDay = st.top();
                while (st.size() && temperatures[prevDay] < temperatures[i]){
                    arr[prevDay] = i - prevDay;
                    st.pop();
                    if (st.size())prevDay = st.top();
                }
            }
            st.push(i);
        }
        return arr;
    }
};