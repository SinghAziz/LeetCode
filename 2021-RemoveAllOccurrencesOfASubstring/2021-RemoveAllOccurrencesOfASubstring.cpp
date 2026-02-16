// Last updated: 16/02/2026, 11:56:43
#include<string>
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int found;
        int size=part.length();
        // cout<<"size: "<<size<<endl;
        while ( s.find(part) != string::npos ){
            found=s.find(part);
            // cout<<s<<" " <<found<<" "<<s[found]<<" "<<s[found+size]<<endl;
            s.erase(found,size);
            // cout<<s<<endl;
    }
    return s;
    }
};