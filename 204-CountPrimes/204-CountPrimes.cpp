// Last updated: 03/07/2026, 11:35:19
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
13        
14        // for (int i = 2; i<n; i++)
15        //     if (sieve[i]) count++;
16        return count-2;
17    }
18};