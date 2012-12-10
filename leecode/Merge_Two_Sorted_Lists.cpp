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
    ListNode *joinNode(ListNode *tail, ListNode *node, ListNode **head_ptr) {
        if (tail == NULL) {
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
        if (*head_ptr == NULL) {
            *head_ptr = tail;
        }
        return tail;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        ListNode *tail = NULL;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                tail = joinNode(tail, p1, &head);
                p1 = p1->next;
            } else {
                tail = joinNode(tail, p2, &head);
                p2 = p2->next;
            }
        }
        while (p1 != NULL) {
            tail = joinNode(tail, p1, &head);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            tail = joinNode(tail, p2, &head);
            p2 = p2->next;
        }
        return head;
    }
};

