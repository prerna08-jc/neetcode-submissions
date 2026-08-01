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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Helper function to find the k-th node from current node
    ListNode* getkth(ListNode* curr, int k) {
        while (curr && k > 1) { // k-1 steps from curr to reach the k-th node
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while (temp) {
            // Find the k-th node from temp
            ListNode* kthNode = getkth(temp, k);
            // If there are fewer than k nodes left, leave them as is
            if (!kthNode) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }
            // Save the starting node of the next group
            ListNode* nextNode = kthNode->next;
            // Detach the current group to reverse it separately
            kthNode->next = nullptr;
            // Reverse the sublist [temp ... kthNode]
            reverse(temp);
            // If this is the first group being reversed, update head
            if (temp == head) {
                head = kthNode;
            } else {
// Otherwise, connect the last group's tail to current group's new head (kthNode)
                prevLast->next = kthNode;
            }
// 'temp' is now the tail of the reversed group; save it as prevLast
            prevLast = temp;
            // Move to the next group
            temp = nextNode;
        }
        return head;
    }
};