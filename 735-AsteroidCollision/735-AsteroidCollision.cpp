// Last updated: 27/03/2026, 01:37:23
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;
        for (auto asteroid : asteroids){
            bool exist = true;
            while (answer.size() && answer.back()>0 && asteroid<0){
                if (answer.back()+asteroid<0){
                    answer.pop_back(); continue;
                }
                if (answer.back()+asteroid==0){
                    answer.pop_back();
                }
                exist = false;
                break;
            }
            if (exist) answer.push_back(asteroid);
        }
        return answer;
    }
};