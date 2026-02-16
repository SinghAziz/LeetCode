// Last updated: 16/02/2026, 11:57:44
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto i:prerequisites){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> order;
        for (int i = 0;i<indegree.size();i++){
            if (!indegree[i]) q.push(i);
        }
        while (q.size()){
            int node = q.front();
            order.push_back(node);
            q.pop();
            for (auto i:adj[node]){
                indegree[i]--;
                if (indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if (order.size()==numCourses) return true;   
        return false;
    }
};