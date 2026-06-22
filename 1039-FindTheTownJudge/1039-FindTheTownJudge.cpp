// Last updated: 22/06/2026, 12:36:43
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n==1 && !trust.size()) return n;
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);
        for (auto i:trust){
            int to = i[1];
            int by = i[0];
            indegree[to]++;
            outdegree[by]++;
        }
        for (auto i:trust){
            int to = i[1];
            int by = i[0];
            if (indegree[to]==n-1 && outdegree[to]==0) return to;
        }
        
        return -1;
    }
};