// Last updated: 19/05/2026, 19:25:03
1class Solution {
2public:
3    string s, t;
4    vector<vector<int>> memo;
5    int subseq(int i, int j){
6        if (j==t.size()) return 1;
7        if (i==s.size()) return 0;
8        if (memo[i][j] != -1) return memo[i][j];
9        if (s[i]==t[j]){
10            int take = subseq(i+1, j+1);
11            int skip = subseq(i+1, j);
12            memo[i][j] =  take + skip;
13        }
14        else{
15            int skip = subseq(i+1, j);
16            memo[i][j] =  skip;
17        }
18        return memo[i][j];
19    }
20    int numDistinct(string s, string t) {
21        this->s = s;
22        this->t = t;
23        int m = s.size();
24        int n = t.size();
25        this->memo = vector<vector<int>> (m, vector<int> (n, -1));
26        return subseq(0, 0);
27    }
28};