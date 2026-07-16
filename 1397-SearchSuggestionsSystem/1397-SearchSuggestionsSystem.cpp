// Last updated: 16/07/2026, 12:29:38
class TrieNode{
    public:
    vector<string> words;
    TrieNode* child[26];
    TrieNode(){
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
        for (int i = 0; i<word.size(); i++){
            int index = word[i] - 'a';
            if (curr->child[index]==NULL){
                TrieNode* temp = new TrieNode();
                curr->child[index] = temp;
            }
            curr = curr->child[index];
            if (curr->words.size()<3)
                curr->words.push_back(word);
        }
    }
    vector<vector<string>> search(string searchWord){
        TrieNode* curr = root;
        vector<vector<string>> answer;
        for (char c : searchWord){
            int index = c-'a';
            if (curr && curr->child[index]){
                curr = curr->child[index];
                answer.push_back(curr->words);
            }
            else {
                curr = NULL;
                answer.push_back({});
            }
        }
        return answer;
    }
}; 
class Solution {
public:
    Trie* root = new Trie();
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for(int i = 0; i<products.size(); i++){
            root->insert(products[i]);
        }
        return root->search(searchWord);
    }
};