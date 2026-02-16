// Last updated: 16/02/2026, 11:57:00
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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        int index = 0;
        ListNode* curr=head;

        while (curr!=nullptr){
            len++;
            curr = curr->next;
        }

        int middle = len/2;
        curr = head;
        while (index<middle){
            curr = curr->next;
            index++;
        }        
        return curr;
    }
};