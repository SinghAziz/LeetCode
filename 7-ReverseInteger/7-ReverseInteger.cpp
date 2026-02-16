// Last updated: 16/02/2026, 11:58:31
class Solution {
public:
    int reverse(int x) {
        int r=0;
        while (x){
                if (r > INT_MAX/10 || r < INT_MIN/10 )
                {
                    return 0;
                }
            r=(r*10)+(x%10);
            x/=10;
            }
            return r;
        }
};