#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	pair<ListNode*, ListNode*> addElem(pair<ListNode*, ListNode*> lst, ListNode *node) {
		ListNode *head = lst.first;
		ListNode *tail = lst.second;
		if (tail == NULL) {
			tail = node;
			head = node;
		} else {
			tail->next = node;
			tail = node;
		}
		return make_pair(head, tail);
	}

	ListNode *partition(ListNode *head, int x) {
		pair<ListNode*, ListNode*> lst0 = make_pair((ListNode*)NULL, (ListNode*)NULL);
		pair<ListNode*, ListNode*> lst1 = make_pair((ListNode*)NULL, (ListNode*)NULL);
		for (ListNode *ptr = head; ptr != NULL; ptr = ptr->next) {
			if (ptr->val < x) {
				lst0 = addElem(lst0, ptr);
			} else {
				lst1 = addElem(lst1, ptr);
			}
		}
		if (lst0.second) {
			lst0.second->next = NULL;
		}
		if (lst1.second) {
			lst1.second->next = NULL;	
		}
		if (lst0.first == NULL) {
			return lst1.first;
		} else if (lst1.first == NULL) {
			return lst0.first;
		} else {
			lst0.second->next = lst1.first;
			return lst0.first;
		}
	}
};

int main() {
	return 0;
}
