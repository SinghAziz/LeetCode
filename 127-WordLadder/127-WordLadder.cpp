// Last updated: 16/02/2026, 11:57:58
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        if (!s.contains(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int words = 1;
        while (!q.empty()){
            int size = q.size();
            for (int h=0; h<size;h++){
                string curr = q.front();
                q.pop();
                for (int i= 0;i<beginWord.size();i++){
                    string next = curr;
                    for (char j= 'a'; j<='z'; j++){
                        next[i]=j;
                        if (next==endWord){
                            return words+1;
                        }
                        if (s.contains(next)){
                            q.push(next);
                            s.erase(next);
                        } 
                    }
              }
            }
            words++;
        }
        return 0;
    }
};