// Last updated: 16/02/2026, 11:57:53
class Solution {
public:
    string reverseWords(string s) {
        string word, ans;
        stringstream ss(s);

        while (ss >> word) {          // auto-skips extra spaces
            ans = word + " " + ans;   // prepend word
        }

        if (!ans.empty())
            ans.pop_back();           // remove trailing space

        return ans;
    }
};
