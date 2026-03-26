// Last updated: 27/03/2026, 01:37:35
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        unordered_map <char, int> mp;
        for (auto i : s) mp[i]++;

        for (auto d : mp){
            int left = 0, count = k;
            char c = d.first;
            for (int right = 0 ;right <n ;right++){       
                if (s[right] != c){
                    count--;
                }
                while (count<0){
                    if (s[left]!=c) count++;
                    left++;
                }
                ans = max(ans, right-left+1);
            }
        }
        return ans;
    }
};