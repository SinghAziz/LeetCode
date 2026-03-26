// Last updated: 27/03/2026, 01:37:06
class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int i =1 ; i<=n ; i++){
            string bin = bitset<32>(i).to_string();     
            bin = bin.substr(bin.find('1'));
            ans = ((ans<<size(bin)) | i) % long (1e9+7);
        }
        return ans;
    }
};