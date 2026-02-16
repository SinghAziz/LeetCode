// Last updated: 16/02/2026, 11:57:43
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto i:prerequisites){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        vector<int> order;
        for (int i =0 ;i <numCourses; i++) {
            if (!indegree[i]) q.push(i);
        }
        while (q.size()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (auto i:adj[node]){
                indegree[i]--;
                if (!indegree[i]) q.push(i);
            }
        }
        if (order.size()!= numCourses) return {};
        return order;
    }
};