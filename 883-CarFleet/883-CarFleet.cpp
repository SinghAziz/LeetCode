// Last updated: 30/04/2026, 19:57:55
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> mp;
        for (int i = 0; i<position.size() ; i++){
            mp.push_back({position[i], speed[i]});
        }
        sort(mp.begin(), mp.end());
        reverse(mp.begin(), mp.end());
        int fleet = 0;
        stack<float>st;
        for (auto i : mp){
            auto [d, s] = pair{target - i.first, i.second};
            float time = float(d)/s;
            st.push(time);
            if (st.size()>=2){
                float top = st.top();st.pop();
                if (st.top()>=top){
                    continue;
                }
                else{
                    st.push(top);
                }
            }
        }
    return st.size();
    }
};