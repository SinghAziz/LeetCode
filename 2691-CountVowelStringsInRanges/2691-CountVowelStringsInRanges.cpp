// Last updated: 22/06/2026, 12:36:15
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n+1, 0);    
        vector<int> ans;
        unordered_map<char, bool> mp;
        mp.insert( {{'a',true} ,
                    {'e',true} , 
                    {'i',true},
                    {'o',true},
                    {'u',true}
    });
        for (int j = 1; j<=n; j++){
            string i = words[j-1];
            if (mp[i[0]] && mp[i.back()]){
                prefix[j] = prefix[j-1]+1;
            }
            else prefix[j] = prefix[j-1];
        }
        for (auto q : queries){
            int left = q[0];
            int right = q[1];
            ans.push_back(prefix[right+1]-prefix[left]);
        }
        return ans;
    }
};