// Last updated: 27/03/2026, 01:37:55
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for (auto i : nums){
            numStrings.push_back(to_string(i));
        }
        sort (numStrings.begin(), numStrings.end(), [](string a, string b) {return a+b > b+a;});

        if (numStrings[0]=="0") return "0";

        string answer;
        for (auto i:numStrings) answer+=i;
        return answer;
    }
};