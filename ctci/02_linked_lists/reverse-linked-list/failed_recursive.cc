/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void reverse(ListNode*& head, ListNode*& iterator)
    {
        printf("!!head=%d, iterator=%d\n", head->val, iterator->val);
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
        reverse(head, head);
        printf("!!head_final=%d\n", head->val);
        return head;
    }
};
