// Last updated: 16/02/2026, 11:57:32
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s.size() - t.size()){
            return false;
        }
        for (int i = 0 ; i<s.size();i++){
            if (s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
};