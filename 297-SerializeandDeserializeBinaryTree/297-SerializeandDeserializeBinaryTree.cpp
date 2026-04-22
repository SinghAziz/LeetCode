// Last updated: 23/04/2026, 02:59:45
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12
13    // Encodes a tree to a single string.
14    string serialize(TreeNode* root) {
15        if (!root) return "null,";
16        string st = to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
17        return st;
18    }
19    // Decodes your encoded data to tree.
20    TreeNode* buildTree(vector<string>& s, int& index){
21        if(s[index]=="null") {index++ ;return NULL; }
22        string val = s[index++];
23        TreeNode* root = new TreeNode(stoi(val));
24        root->left = buildTree(s, index);
25        root->right = buildTree(s, index);
26        return root;
27    }
28    TreeNode* deserialize(string data) {
29        vector<string> s;
30        string temp;
31        for (char c : data){
32            if (c==','){
33                s.push_back(temp);
34                temp="";
35            }
36            else{
37                temp+=c;
38            }
39        }
40        int i = 0;
41        return buildTree(s, i);
42    }
43};
44
45// Your Codec object will be instantiated and called as such:
46// Codec ser, deser;
47// TreeNode* ans = deser.deserialize(ser.serialize(root));