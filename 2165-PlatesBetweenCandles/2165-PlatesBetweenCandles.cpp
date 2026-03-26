// Last updated: 27/03/2026, 01:37:03
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> answer;
        vector<int> prefix(n,0);
        vector<int> leftCandle(n,-1);
        vector<int> rightCandle(n,-1);
        int last = -1;
        for (int i=0 ;i<n ;i++){
            prefix[i]= ( i>0 ? prefix[i-1] : 0 )+ (s[i]=='*');
            if (s[i]=='|') last = i;
            leftCandle[i] = last;
        }
        last = -1;
        for (int i = n-1; i>=0 ;i--){
            if (s[i]=='|') last = i;
            rightCandle[i] = last;
        }
        for (auto q : queries){
            int l = rightCandle[q[0]];
            int r = leftCandle[q[1]];
            if (l!=-1 && r!=-1 && l<r) answer.push_back(prefix[r]-prefix[l]);
            else answer.push_back(0);
        }
        return answer;
    }
};