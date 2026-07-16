// Last updated: 16/07/2026, 12:29:19
int ans;
class TrieNode{
    public:
    TrieNode* child[2];
    int count;
    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
        count = 0;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int n){
        TrieNode* curr = root;
        for (int i = 31; i>=0 ; i--){
            int bit = (n>>i) & 1;
            if (curr->child[bit]==NULL){
                TrieNode* temp = new TrieNode();
                curr->child[bit] = temp;
            }
            curr = curr->child[bit];
            curr->count++;
        }
    }
    void search(int n){
        TrieNode* curr = root;
        int sum = 0;
        for (int i = 31; i>=0 ; i--){
            int bit = (n>>i) & 1; // to check is set or not
            if (curr->child[!bit] && curr->child[!bit]->count){
                sum += (1<<i);
                curr = curr->child[!bit];
            }
            else{
                curr = curr->child[bit];
            }
        }
        ans = max(ans, sum);
    }
    void erase(int n){
        TrieNode* curr = root;
        for (int i = 31; i>=0; i--){
            int bit = (n>>i) & 1; //set or not
            curr->child[bit]->count--;
            curr = curr->child[bit];
        }
    }
};

class Solution {
public:
    Trie* root = new Trie();
    int maximumStrongPairXor(vector<int>& nums) {
        ans = 0;
        sort(nums.begin() , nums.end());
        int i = 0;
        for (int j = i; j<nums.size(); j++){
            root->insert(nums[j]);
            while (nums[j]>2*nums[i]){
                root->erase(nums[i]);
                i++;
            }
            root->search(nums[j]);
        }
        return ans;
    }
};