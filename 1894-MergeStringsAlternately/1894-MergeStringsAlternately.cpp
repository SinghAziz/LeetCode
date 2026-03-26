// Last updated: 27/03/2026, 01:37:05
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int n = max(n1, n2);
        int i = 0;
        string answer = "";
        while (i<n){
            if (i<n1) answer+=word1[i];
            if (i<n2) answer+=word2[i];
            i++;
        }
        return answer;
    }
};