// Last updated: 27/03/2026, 01:38:04
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), answer = 0;
        vector<int> v(n, 1);
        //Left to Right
        for (int i=1 ; i<n ; i++){
            if (ratings[i]>ratings[i-1]) v[i]=v[i-1]+1;
        }
        answer=v.back();
        //Right to Left
        for (int i=n-2 ;i>=0 ;i--){
            if (ratings[i]>ratings[i+1]) v[i] = max(v[i], v[i+1] + 1);
            answer+=v[i];
        }
        return answer;
    }
};