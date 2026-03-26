// Last updated: 27/03/2026, 01:37:53
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp_s_to_t;
        unordered_map<char, char> mp_t_to_s;
        for (int i = 0; i<s.size();i++){
            if (!mp_s_to_t[s[i]] && !mp_t_to_s[t[i]]){
                mp_s_to_t[s[i]] = t[i];
                mp_t_to_s[t[i]] = s[i];
            }
            else if (mp_s_to_t[s[i]]!=t[i] || mp_t_to_s[t[i]] != s[i]) return false;
        }
        return true;
    }
};