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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* iterator = head;
        
        while (iterator != nullptr) {
            ListNode* sub_iterator = iterator->next;
            while (sub_iterator != nullptr && sub_iterator->val == iterator->val) {
                sub_iterator = sub_iterator->next;
            }
            iterator->next = sub_iterator;
            iterator = iterator->next;
        }
        
        return head;
    }
};
