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
    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return NULL;
        }
        if (l == r) {
            return lists[l];
        }
        int mid = l + (r - l) / 2;
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);
        return mergeTwoLists(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }
        return divide(lists, 0, n - 1);
    }
};
