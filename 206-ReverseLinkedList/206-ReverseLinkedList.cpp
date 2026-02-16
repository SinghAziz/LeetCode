// Last updated: 16/02/2026, 11:57:46
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // save next
            curr->next = prev;              // reverse pointer
            prev = curr;                    // move prev ahead
            curr = nextNode;                // move curr ahead
        }
        
        return prev; // prev becomes new head
    }
};
