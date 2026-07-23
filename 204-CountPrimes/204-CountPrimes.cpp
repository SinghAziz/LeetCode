// Last updated: 24/07/2026, 00:03:35
1class Solution {
2public:
3    int countPrimes(int n) {
4        vector<bool> sieve(n, true);
5        if (n==0 || n==1) return 0;
6        int count = n;
7        for (int i = 2; i*i<n; i++)
8            if (sieve[i])
9                for (int j = i*i; j<n; j=j+i){
10                    if (sieve[j]) count--;
11                    sieve[j] = false;
12                }
13        return count-2;
14    }
15};