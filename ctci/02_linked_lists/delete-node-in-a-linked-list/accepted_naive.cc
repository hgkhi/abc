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
 *
 * Naive as fuck!
 */

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        while (node->next != nullptr) {
            node->val = node->next->val;
            if (node->next->next == nullptr) {
                node->next = nullptr;
            } else {
                node = node->next;
            }
        }
    }
};
