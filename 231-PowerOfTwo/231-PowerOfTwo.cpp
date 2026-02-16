// Last updated: 16/02/2026, 11:57:35
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0)
            return false;
        return (n&(n-1))==0; 
    }
};