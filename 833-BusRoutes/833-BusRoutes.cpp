// Last updated: 16/02/2026, 11:57:03
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        unordered_map<int, vector<int>> mp;
        //If Source is already equal to destination
        if (source == target) return 0;
        //Creating Adj list
        for(int i = 0 ; i<routes.size() ; i++){
            for (auto& route : routes[i]){
                mp[route].push_back(i);
            }
        }
        queue<int> q;
        set<int> seen;
        //Adding routes of source to the queue
        for(auto i: mp[source]){
            q.push(i);
            seen.insert(i); //To remember the route we have seen
        }
        int train = 1;
        while(q.size()){
            int level = q.size();
            while (level--){
                //Traverse the stations in the route
                int route = q.front();
                q.pop();
                for (auto i : routes[route]){
                    if (i==target) return train;
                    for (auto route : mp[i]){
                        if (!seen.count(route)){
                            seen.insert(route);
                            q.push(route);
                        }
                    }
                }

            }
            train++;
        }
        return -1;
    }
};