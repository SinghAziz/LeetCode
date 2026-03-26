// Last updated: 27/03/2026, 01:37:16
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxPQ;
        for (int i=0 ;i < points.size();i++){
            pair<int, int> entry = {squaredDistance(points[i]),i};
            if (maxPQ.size()<k){//space available in the window
                maxPQ.push(entry);
            }
            else if (entry.first<maxPQ.top().first){
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }

        //Storing Vals in vector
        vector<vector<int>> answer;
        while (!maxPQ.empty()){
            answer.push_back(points[maxPQ.top().second]);
            maxPQ.pop();
        }
        return answer;
    }

    private:
        int squaredDistance(vector<int> &point){
            return point[0]*point[0] + point[1]*point[1];
        }
};
