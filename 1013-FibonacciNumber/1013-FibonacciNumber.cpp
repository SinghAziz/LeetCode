// Last updated: 16/02/2026, 11:56:59
class Solution {
public:
    int fib(int n) {
        if (n<1){
            return 0;
        }
        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;
        
        for (int i = 2 ; i<=n ; i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};