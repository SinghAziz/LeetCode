// Last updated: 16/02/2026, 11:58:30
class Solution {
public:
    int romanToInt(string s) {
        vector<pair<char, int>> list;
        list.push_back({'I', 1});
        list.push_back({'V', 5});
        list.push_back({'X', 10});
        list.push_back({'L', 50});
        list.push_back({'C', 100});
        list.push_back({'D', 500});
        list.push_back({'M', 1000});
        int ans = 0;
        char prev;
        for (auto i:s){
            for (auto j:list){
                if (i==j.first){
                    if ( (i=='V' || i=='X') && prev =='I'){
                        ans+=(j.second-2);
                    }
                    else if ( (i=='L' || i=='C') && prev == 'X'){
                        ans+=(j.second-20);
                    }
                    else if ( (i=='D' || i=='M') && prev == 'C'){
                        ans+=(j.second-200);
                    }
                    else{
                    ans+=j.second;
                    }
                    prev = j.first;
                }
            }
        }
        return ans;
    }
};