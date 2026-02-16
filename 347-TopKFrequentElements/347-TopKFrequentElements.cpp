// Last updated: 16/02/2026, 11:57:23
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;  // Count frequencies

        // Min-heap: pair<frequency, number>
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto& [num, count] : freq) {
            pq.push({count, num});          // push (frequency, number)
            if (pq.size() > k) pq.pop();    // keep only k elements
        }

        // Extract results
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        reverse(result.begin(), result.end());  // optional: largest frequency first
        return result;
    }
};
