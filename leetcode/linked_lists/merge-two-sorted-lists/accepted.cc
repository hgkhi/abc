/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
* Runtime   O(n)
* Space     O(1)
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(-1);
        ListNode* tail = dummy_head;
        
        while (l1 != nullptr || l2 != nullptr) {
            int val1 = l1 != nullptr ? l1->val : INT_MAX;
            int val2 = l2 != nullptr ? l2->val : INT_MAX;
            if (val1 < val2) {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        
        ListNode* head = dummy_head->next;
        delete dummy_head;
        return head;
    }
};
