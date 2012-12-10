#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

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
    ListNode* addElem(int val, ListNode *tail) {
        ListNode *nxt = new ListNode(val);
        nxt->next = NULL;
        if (tail == NULL) {
            tail = nxt;
        } else {
            tail->next = nxt;
            tail = tail->next;
        }
        return tail;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL, *tail = NULL;
        priority_queue< pair<int, ListNode*> > Q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                Q.push(make_pair(-(lists[i]->val), lists[i]));
            }
        }
        while (!Q.empty()) {
            pair<int, ListNode*> cur = Q.top();
            Q.pop();
            tail = addElem(-cur.first, tail);
            if (head == NULL) {
                head = tail;
            }
            ListNode *nxt = cur.second->next;
            if (nxt != NULL) {
                Q.push(make_pair(-nxt->val, nxt));
            }
        }
        return head;
    }
};

int main() {
	Solution s;
	return 0;
}
