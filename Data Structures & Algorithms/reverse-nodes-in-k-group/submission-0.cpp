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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        // 1. Check if there are at least k nodes present
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        // 2. If we found k nodes, reverse them
        if (count == k) {
            // Recursively process the rest of the list first
            ListNode* reversedRest = reverseKGroup(curr, k);
            // Reverse the current block of k nodes and link its tail to reversedRest
            ListNode* prev = reversedRest;
            curr = head;
            while (count > 0) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count--;
            }
            // 'prev' is now the new head of this reversed block
            return prev;
        }
        // If fewer than k nodes remain, leave them untouched
        return head;
    }
};