// Last updated: 26/06/2026, 11:57:17
1class TrieNode {
2public:
3    bool isEnd;
4    int count;
5    TrieNode* child[26];
6    TrieNode() {
7        isEnd = false;
8        count = 0;
9        for (int i = 0; i < 26; i++)
10            child[i] = NULL;
11    }
12};
13class MapSum {
14public:
15    TrieNode* root;
16    unordered_map<string, int> mp;
17    MapSum() { 
18        root = new TrieNode(); 
19    }
20
21    void insert(string key, int val) {
22        TrieNode* curr = root;
23        // checking if exists
24        int prev = 0;
25        if (mp.find(key) != mp.end()) prev = mp[key];
26        mp[key] = val;
27        int diff = val-prev;
28        for (int i = 0; i < key.size(); i++) {
29            int index = key[i] - 'a';
30            if (curr->child[index] == NULL) {
31                TrieNode* temp = new TrieNode();
32                curr->child[index] = temp;
33            }
34            curr = curr->child[index];
35            curr->count += val;
36        }
37        if (curr->isEnd) // already exists
38        {
39            // Traverse and replace the counts
40            TrieNode* curr = root;
41            for (int i = 0; i < key.size(); i++) {
42                int index = key[i] - 'a';
43                curr->child[index]->count -= prev;
44                curr = curr->child[index];
45            }
46        }
47        curr->isEnd = true;
48    }
49
50    int sum(string prefix) {
51        TrieNode* curr = root;
52        for (int i = 0; i < prefix.size(); i++) {
53            int index = prefix[i] - 'a';
54            if (curr->child[index] == NULL)
55                return 0;
56            curr = curr->child[index];
57        }
58        return curr->count;
59    }
60};
61
62/**
63 * Your MapSum object will be instantiated and called as such:
64 * MapSum* obj = new MapSum();
65 * obj->insert(key,val);
66 * int param_2 = obj->sum(prefix);
67 */