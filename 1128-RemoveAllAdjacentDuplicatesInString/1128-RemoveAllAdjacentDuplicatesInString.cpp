// Last updated: 16/02/2026, 11:56:54
class Solution {
public:
    string removeDuplicates(string s) {
        int i=1;
            while (i<s.length()){
                if (s[i]==s[i-1] ) {
                    cout<<"s[i-1]:"<<s[i-1]<<" s[i]:"<<s[i]<<endl;
                    s.erase(i-1,2);
                    i=1;
                }
                else{
                    if (s.length()==2){
                        return s;
                    }
                    i++;
                }
            }   
        return s;
    }
};