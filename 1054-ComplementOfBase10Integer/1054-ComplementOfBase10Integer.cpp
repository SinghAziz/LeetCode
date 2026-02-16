// Last updated: 16/02/2026, 11:56:56
class Solution {
public:
    int bitwiseComplement(int n) {
        int m=0;
        int a=n;
        if (n==0)
            return 1;
        
        while (n!=0){
            m=(m<<1)|(1);
            n=n>>1;
        }
        n=(~a)& m;
        return n;
    }
};