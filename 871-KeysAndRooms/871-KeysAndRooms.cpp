// Last updated: 16/02/2026, 11:57:02
class Solution {
public:
    void DFS(vector<vector<int>>&rooms, int k , vector<bool>& visited){
        int r = rooms.size();
        int c = rooms[0].size();
        for (auto j : rooms[k]){
            if (!visited[j]){
                visited[j]=true;
                DFS(rooms, j , visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int r = rooms.size();
        int c = rooms[0].size();
        vector<bool> visited(r, false);
        DFS(rooms,0, visited);
        visited[0]=true;
        for (bool i : visited){
            if (!i){
                return false;
            }
        }
        return true;
    }
};