// Last updated: 27/03/2026, 01:37:18
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map <int, int> visited;
        int left = 0, ans = 0, right =0;
        for (; right<n; right++){
            visited[fruits[right]]++;
            if (visited.size()>2){
                visited[fruits[left]]--;
                if (!visited[fruits[left]]) visited.erase(fruits[left]);
                left++;
            }
        }
        return right - left;
    }
};