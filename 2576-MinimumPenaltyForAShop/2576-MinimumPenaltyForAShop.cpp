// Last updated: 22/06/2026, 12:36:16
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix (n+1, 0);
        vector<int> suffix (n+1, 0);
        vector<int> master (n+1,0);
        //Building Prefix
        for (int i = 1 ; i<=n ;i++){
            if (customers[i-1]=='N')
                prefix[i] = prefix[i-1] + 1;
            else 
                prefix[i] = prefix[i-1];
        }
        //Building Suffix
        for (int i = n-1; i>=0 ;i--){
            if (customers[i]=='Y')
                suffix[i] = suffix[i+1] +1 ;
            else 
                suffix[i] = suffix[i+1];
        }

        //Master Array
        for (int i = 0; i<=n; i++){
            master[i] = prefix[i] + suffix[i];
        }
        int index, mini = INT_MAX;
        for (int i = 0; i<=n; i++){
            if (master[i]<mini){
                mini = master[i];
                index = i;
            }
        }
        return index;
    }
};