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
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* result = nullptr;
        
        while (true) {
            if (p2->next != nullptr) {
                if (p2->next->next != nullptr) {
                    // P2 can push 2 nodes
                    p2 = p2->next->next;
                    p1 = p1->next;
                } else {
                    // P2 can push only one node
                    result = p1->next;
                    break;
                }
            } else {
                result = p1;
                break;
            }
        }            
        
        return result;
    }
};
