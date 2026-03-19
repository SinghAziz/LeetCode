// Last updated: 19/03/2026, 12:55:59
1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        unordered_set<int> st;
5
6        int maxi=0;
7
8        for (int i: nums){
9            st.insert(i);
10            maxi=max(i, maxi);
11        }
12
13        for (int i=1;i<=maxi;i++){
14            if (st.find(i)!=st.end()) continue;
15            else return i;
16        }
17        return maxi+1;
18    }
19};