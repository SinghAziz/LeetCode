// Last updated: 16/02/2026, 11:56:47
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for (int i : arr){
            map[i]++;
        }
        unordered_set<int> seen;
        for (auto &i : map){
            int val =i.second;
            if ( seen.count(val)){
                return false;
            }
            seen.insert(val);
        }
        return true;
    }
};