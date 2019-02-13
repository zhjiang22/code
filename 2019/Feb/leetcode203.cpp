/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head, *q = head -> next;
        while (q != NULL) {
            if (q -> val == val) {
                p -> next = q -> next;
                q = q -> next;
            }
            else {
                p = q;
                q = q -> next;
            }
        }
        if (head -> val == val) return head -> next;
        else    return head;
    }
};