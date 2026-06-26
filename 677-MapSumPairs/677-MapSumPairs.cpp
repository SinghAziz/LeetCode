// Last updated: 26/06/2026, 11:58:44
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
35            curr->count += diff;
36        }
37        // if (curr->isEnd) // already exists
38        // {
39        //     // int prev = mp[key];
40        //     // Traverse and replace the counts
41        //     TrieNode* curr = root;
42        //     for (int i = 0; i < key.size(); i++) {
43        //         int index = key[i] - 'a';
44        //         curr->child[index]->count += val - prev;
45        //         curr = curr->child[index];
46        //     }
47        // }
48        // curr->isEnd = true;
49    }
50
51    int sum(string prefix) {
52        TrieNode* curr = root;
53        for (int i = 0; i < prefix.size(); i++) {
54            int index = prefix[i] - 'a';
55            if (curr->child[index] == NULL)
56                return 0;
57            curr = curr->child[index];
58        }
59        return curr->count;
60    }
61};
62
63/**
64 * Your MapSum object will be instantiated and called as such:
65 * MapSum* obj = new MapSum();
66 * obj->insert(key,val);
67 * int param_2 = obj->sum(prefix);
68 */