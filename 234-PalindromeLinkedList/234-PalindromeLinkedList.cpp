// Last updated: 27/03/2026, 01:37:46
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *f = head;
        vector<int> nums;
        while (f!=NULL){
            cout << f->val << " ";
            nums.push_back(f->val);
            f=f->next;
        }
        // for (auto i:nums) cout<<i<<" ";
        int i = 0;
        int j = nums.size()-1;
        while (i<=j){
            if (nums[i]!=nums[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};