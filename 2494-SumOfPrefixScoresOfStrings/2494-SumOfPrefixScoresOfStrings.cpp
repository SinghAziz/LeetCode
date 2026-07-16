// Last updated: 16/07/2026, 12:29:24
int index_curr;
vector<int> final;
class TrieNode{
    public:
    int count;
    vector<int> index_word;
    bool isEnd;
    TrieNode *child[26];
    TrieNode(){
        isEnd = false;
        count = 0;
        for (int i = 0; i<26; i++) child[i] = NULL;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* curr = root;
        for (auto c : word){
            int index = c-'a';
            if (curr->child[index] == NULL){
                TrieNode* temp = new TrieNode();
                curr->child[index] = temp;
            }
            curr->child[index]->count++;
            curr = curr->child[index];
        }
        curr->isEnd = true;
        curr->index_word.push_back(index_curr);
    }
    void search(TrieNode* curr, int ans){
        if (curr->isEnd){
            vector<int>index_word = curr->index_word;
            for (int i = 0; i<index_word.size(); i++){
                if (index_word[i]==-1) continue;
                final[index_word[i]] = ans;
                index_word[i] = -1;
            }
        }
        for (int i = 0; i<26; i++){
            if (curr->child[i]) {
                search(curr->child[i], ans+curr->child[i]->count);
            }
        }
    }
};
class Solution {
public:
    Trie *root = new Trie();
    vector<int> sumPrefixScores(vector<string>& words) {
        final.resize(words.size());
        for (int i = 0; i<words.size(); i++){
            index_curr = i;
            root->insert(words[i]);
        }
        root->search(root->root,0);
        return final;
    }
};