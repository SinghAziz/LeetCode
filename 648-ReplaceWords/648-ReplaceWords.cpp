// Last updated: 26/06/2026, 10:54:20
1class TrieNode{
2    public:
3    bool isEnd;
4    TrieNode* child[26];
5    TrieNode(){
6        isEnd = false;
7        for (int i = 0; i<26; i++) child[i] = NULL;
8    }
9};
10
11class Trie{
12    public:
13    TrieNode* root;
14    Trie(){
15        root = new TrieNode();
16    }
17    void insert(string word){
18        TrieNode* curr = root;
19        for (int i = 0; i<word.size(); i++){
20            int index = word[i] - 'a';
21            if (curr->child[index]==NULL){ //absent
22                TrieNode* temp = new TrieNode();
23                curr->child[index] = temp;
24            }   
25            curr = curr->child[index];
26        }
27        curr->isEnd = true;
28    }
29    string search(string word){
30        string ans;
31        TrieNode* curr = root;
32        for (int i = 0; i<word.size(); i++){
33            int index = word[i]-'a';
34            if (curr->child[index]==NULL){
35                return word;
36            }
37            ans+=word[i];
38            if (curr->child[index]->isEnd==true) return ans;
39            curr = curr->child[index];
40        }
41        return ans;
42    }
43};
44class Solution {
45public:
46    Trie* root = new Trie();
47    string replaceWords(vector<string>& dictionary, string sentence) {
48        vector<string> words;
49        for (auto i : dictionary) root->insert(i);
50        string word;
51        for (int i = 0; i<sentence.size(); i++){ // try another variation too
52            char curr = sentence[i];
53            if (curr!=' ') word+=curr;
54            if (curr==' ') {
55                words.push_back(word);
56                word="";
57            }
58            if (i==sentence.size()-1){
59                words.push_back(word);
60            }
61        }
62        vector<string> ans;
63        for (int i = 0; i<words.size(); i++){
64            ans.push_back(root->search(words[i]));
65        }
66        string built;
67        for (int i = 0; i<ans.size(); i++){
68            built+=ans[i];
69            if (i!=ans.size()-1){
70                built+=" ";
71            }
72        }
73        return built;
74    }
75};