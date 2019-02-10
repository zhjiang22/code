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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a[100005] = {0}, b[100005] = {0};
        int L1 = 0, L2 = 0;
        ListNode *p = l1, *q = l2;
        while (p != NULL) {
            a[L1++] = p -> val;
            p = p -> next;
        }
        while (q != NULL) {
            b[L2++] = q -> val;
            q = q -> next;
        }
        int l = max(L1, L2);
        int cur = 0;
        for (int i = 0; i < l; i++) {
            a[i] += b[i] + cur;
            cur = a[i] / 10;
            a[i] %= 10;
        }
        if (cur)    a[++l] = cur;
        ListNode x = ListNode(0);
        ListNode *r = &x;
        for (int i = 0; i < l; i++) {
            r -> val = a[i];
            x = ListNode(0);
            r -> next = &x;
            r = r -> next;
        }
        r -> next = NULL;
    }
    return r;
};



