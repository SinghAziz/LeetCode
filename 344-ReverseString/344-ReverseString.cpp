// Last updated: 16/02/2026, 11:57:25
#include<iostream>
#include<vector>
class Solution {
public:
    void reverseString(vector<char>& s) {
        int a=0, e=s.size()-1;
        while (a<e){
            swap(s[a++], s[e--]);
        }
        // for (char c:s){
        //     cout<<c;
        // }
    }
};