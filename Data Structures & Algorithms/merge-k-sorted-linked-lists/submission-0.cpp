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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                node->next = list2;
                list2 = list2->next;
            } else {
                node->next = list1;
                list1 = list1->next;
            }
            node = node->next;
        }
        if (list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }
        ListNode* l1 = lists[0];
        for (int i = 1; i < n; i++) {
            ListNode* l2 = lists[i];
            l1 = mergeTwoLists(l1, l2);
        }
        return l1;
    }
};
