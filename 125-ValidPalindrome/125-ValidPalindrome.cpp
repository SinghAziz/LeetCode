// Last updated: 16/02/2026, 11:57:59
class Solution {
public:
    bool isPalindrome(string s) {
        string check;
        for (auto i : s){
            if (isalnum(i)){
                check+=tolower(i);
            }
        }
        //comparing
        for ( int i =0 ; i<check.size()/2; i++){
            if (check[i] != check[check.size()-1-i])
            return false;
        }
        return true;
    }
};