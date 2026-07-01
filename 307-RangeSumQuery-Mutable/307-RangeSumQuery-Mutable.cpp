// Last updated: 01/07/2026, 15:19:27
1class NumArray {
2public:
3    vector<int> query;
4    int n;
5    NumArray(vector<int>& nums) {
6        query.resize(4*nums.size());
7        build(nums, 0, 0, nums.size()-1);
8        n = nums.size();
9    }
10    
11    void build(vector<int>& nums, int v, int ql ,int qr){
12        if (ql==qr){
13            query[v] = nums[ql];
14        }
15        else{
16            int mid = (ql+qr)>>1;
17            build(nums, v*2+1, ql, mid);
18            build(nums, v*2+2, mid+1, qr);
19            query[v] = query[v*2+1] + query[v*2+2];
20        }
21    }
22
23    void updation(int index, int pos, int val, int l, int r){
24        if (l == r){
25            query[index] = val;
26            return;
27        }
28        int mid = (l+r)>>1;
29        if (pos<=mid){//go to left
30            updation(2*index+1, pos, val, l, mid);
31        }
32        else{
33            updation(2*index+2, pos, val, mid+1, r);
34        }
35        query[index] = query[2*index+1] + query[2*index+2];
36    }
37
38    void update(int index, int val) {
39        updation(0, index, val, 0, n-1);
40    }
41    
42    int findSum(int index, int left, int right, int ql, int qr){
43        if (right<ql || left>qr) return 0;
44        if (ql<=left && qr>=right) return query[index];
45        int mid = (left+right)>>1;
46        int l = findSum(2*index+1, left, mid , ql, qr);
47        int r = findSum (2*index+2, mid+1 , right, ql, qr);
48        return l+r;
49    }
50    int sumRange(int left, int right) {
51        return findSum(0, 0, n-1, left, right);
52    }
53};
54
55/**
56 * Your NumArray object will be instantiated and called as such:
57 * NumArray* obj = new NumArray(nums);
58 * obj->update(index,val);
59 * int param_2 = obj->sumRange(left,right);
60 */