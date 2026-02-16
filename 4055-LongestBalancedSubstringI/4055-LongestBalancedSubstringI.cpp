// Last updated: 16/02/2026, 11:56:42
class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1;
        for (int left = 0 ; left<s.size();left++){
            unordered_map<char, int> freq = {};
            int maxFreq = 0;
            for (int right= left; right<s.size();right++){
                freq[s[right]]++;
                maxFreq = max(maxFreq, freq[s[right]]);
                int minFreq = INT_MAX;
                for (auto &p : freq) {
                    minFreq = min(minFreq, p.second);
                }                
                if (maxFreq==minFreq){
                    ans = max(ans, right -left+1);
                }
            }
        }
        return ans;
    }
};