// Last updated: 16/07/2026, 12:29:31
class TrieNode{
    public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = NULL;
        child[1] = NULL;
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
        for (int i = 31; i>=0; i--){
            int bit = (n>>i) & 1; //to check set or not
            if (curr->child[bit]==NULL){
                TrieNode* temp = new TrieNode();
                curr->child[bit] = temp;
            }
            curr = curr->child[bit];
        }
    }
    int search(int n){
        TrieNode* curr = root;
        int ans = 0;
        for (int i = 31; i>=0; i--){
            int bit = (n>>i) & 1; //to check set or not 
            if (curr->child[!bit]){
                ans+= 1<<i;
                curr=curr->child[!bit];
            }
            else{
                curr=curr->child[bit];
            }
        }
        return ans;
    }
};
class Solution {
public:
    Trie* root = new Trie();
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i<queries.size(); i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(),[&] (auto a, auto b){return a[1]<b[1];} );
        vector<int> answer(queries.size());
        int z = 0;
        for (int i = 0; i<queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];
            for(int j = z; j<nums.size(); j++){
                if (nums[j]>v) break;
                root->insert(nums[j]);
                z++;
            }
            if (z==0) {
                answer[queries[i][2]] = -1;
                continue;
            }
            answer[queries[i][2]] = root->search(u);
        }
        return answer;
    }
};