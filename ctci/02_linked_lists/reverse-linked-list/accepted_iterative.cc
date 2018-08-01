/*
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
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* iterator = head;
        ListNode* temp = nullptr;
        
        while (iterator->next != nullptr) {
            temp = iterator->next;
            iterator->next = iterator->next->next;
            temp->next = head;
            head = temp;
        }
        
        return head;
    }
};
