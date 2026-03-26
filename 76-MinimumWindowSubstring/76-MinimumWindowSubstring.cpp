// Last updated: 27/03/2026, 01:39:52
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto a : t) mp[a]++;
        int count = t.size();
        int left = 0, start = 0;
        int minLen = INT_MAX;
        for (int right = 0;right<s.size();right++){
            if (mp[s[right]]>0) count--;
            mp[s[right]]--;
            while (count==0){
                if (right-left+1<minLen){
                    minLen = right -left+1;
                    start=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0) count++;
                left++;
            }
        }
        return minLen==INT_MAX ? "" : s.substr(start, minLen);
    }
};