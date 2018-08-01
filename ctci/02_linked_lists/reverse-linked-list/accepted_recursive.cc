/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Runtime  O(n)
 * Space    O(1)
 */
class Solution {
private:
    void reverse(ListNode*& head, ListNode*& iterator)
    {
        if (head == nullptr || iterator->next == nullptr) {
            return;
        }
        
        ListNode* temp = iterator->next;
        iterator->next = iterator->next->next;
        temp->next = head;
        head = temp;
        reverse(head, iterator);
    }
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* iterator = head;
        reverse(head, iterator);
        return head;
    }
};
