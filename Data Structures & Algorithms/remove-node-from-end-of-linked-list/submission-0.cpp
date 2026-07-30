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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int m = 0;
        while (curr) {
            m++;
            curr = curr->next;
        }
        int x = m - n;
        if (x == 0) {
            return head->next;
        }
        curr = head;
        for (int i = 0; i < m - 1; i++) {
            if ((i + 1) == x) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
