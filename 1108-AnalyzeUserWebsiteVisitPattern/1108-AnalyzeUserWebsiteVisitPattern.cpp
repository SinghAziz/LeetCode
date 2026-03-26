// Last updated: 27/03/2026, 01:37:12
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        vector<tuple<int, string, string>> visits;
        for (int i = 0 ;i<n ;i++) visits.push_back({timestamp[i], username[i], website[i]});
        sort(visits.begin(),visits.end()); //sorting according to the timestamp
        unordered_map <string, vector<string>> user_map; //to store websites visited by a user. 
        for (auto v :visits) user_map[get<1>(v)].push_back(get<2>(v));
        // Now we will store the number of times a pattern occured
        map<vector<string>, int> pattern_count;
        for (auto it : user_map){
            auto &sites = it.second;
            int m = sites.size();
            set<vector<string>> seen;

            for (int i = 0 ;i <m ;i++){
                for (int j= i+1 ; j<m ;j++){
                    for (int k = j+1 ; k<m ;k++){
                        vector<string> pattern ={sites[i], sites[j], sites[k]}; //to store the 3 occurences
                        seen.insert(pattern);
                    }
                }
            }
            for (auto p:seen){
                pattern_count[p]++;
            }
        } 

        vector<string> answer;
        int max_count = 0;
        for (auto i : pattern_count){
            if (i.second>max_count){
                max_count = i.second;
                answer = i.first;
            }
        }
        return answer;
    }
};