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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num = 0, carry = 0;
        ListNode *p1 = l1, *p2 = l2;
        ListNode *ret = NULL, *cur = NULL;
        while (p1 != NULL || p2 != NULL) {
            num = carry;
            if (p1) {
                num += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                num += p2->val;
                p2 = p2->next;
            }
            carry = (num > 9 ? 1 : 0);
            num %= 10;
            if (cur == NULL) {
                cur = new ListNode(num);
                ret = cur;
            } else {
                cur->next = new ListNode(num);
                cur = cur->next;
            }
        }
        if (carry) {
            cur->next = new ListNode(1);
        }
        return ret;
    }
};

