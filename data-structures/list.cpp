#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

// Single-linked list

struct Node {
	int v;
	Node *next;
};

class LinkedList {
	Node *head;	// empty node
public:
	LinkedList() {
		head = new Node();
		head->next = NULL;
	}

	~LinkedList() {
		Node *pre = head;
		for (Node *cur = pre->next; cur != NULL; cur = pre->next) {
			delete pre;
			pre = cur;
		}
		delete pre;
		head = NULL;
	}

	void insert(int x) {
		Node *cur = new Node();
		cur->v = x;
		cur->next = head->next;
		head->next = cur;
	}

	void remove(int x) {
		Node *pre = head;
		for (Node *cur = head->next; cur != NULL; ) {
			if (cur->v != x) {
				pre = cur;
			} else {
				pre->next = cur->next;
				delete cur;
			}
			cur = pre->next;
		}
	}

	// for debugging
	void show() {
		printf("list : ");
		for (Node *cur = head->next; cur != NULL; cur = cur->next)
			printf("%d ", cur->v);
		puts("");
	}
};

// Double-linked list
struct DoubleNode {
	int v;
	DoubleNode *prev;
	DoubleNode *next;
};

class DoubleLinkedList {
	DoubleNode *head;	// empty node
	DoubleNode *tail;	// empty node
public:
	DoubleLinkedList() {
		head = new DoubleNode();
		tail = new DoubleNode();
		head->v = 0;
		head->prev = NULL;
		head->next = tail;
		tail->v = 0;
		tail->prev = head;
		tail->next = NULL;
	}
	
	~DoubleLinkedList() {
		DoubleNode *pre = head;
		for (DoubleNode *cur = pre->next; cur != NULL; cur = pre->next) {
			delete pre;
			pre = cur;
		}
		delete pre;
		head = tail = NULL;
	}

	void insertBeginning(int x) {
		DoubleNode *cur = new DoubleNode();
		cur->v = x;
		cur->prev = head;
		cur->next = head->next;
		head->next->prev = cur;
		head->next = cur;
	}

	void insertEnd(int x) {
		DoubleNode *cur = new DoubleNode();
		cur->v = x;
		cur->prev = tail->prev;
		cur->next = tail;
		tail->prev->next = cur;
		tail->prev = cur;
	}

	void remove(int x) {
		for (DoubleNode *cur = head->next; cur != tail; ) {
			if (cur->v != x) {
				cur = cur->next;
			} else {
				DoubleNode *nxt = cur->next;
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				cur = nxt;
			}
		}
	}

	// for debugging
	void show() {
		printf("double-list : ");
		for (DoubleNode *cur = head->next; cur != tail; cur = cur->next)
			printf("%d ", cur->v);
		puts("");
	}
};

// Circularly Linked List
class CircularLinkedList {
	DoubleNode *head;	// contains data, so do remember to update the head node in 'insert' calls and
				//	keep track of the modifications in 'remove' calls.
public:
	CircularLinkedList() {
		head = NULL;
	}

	~CircularLinkedList() {
		if (head) {
			DoubleNode *pre = head;
			for (DoubleNode *cur = pre->next; cur != head; cur = pre->next) {
				delete pre;
				pre = cur;
			}
			delete pre;
			head = NULL;
		}
	}

	void insert(int x) {
		if (!head) {
			head = new DoubleNode();
			head->v = x;
			head->prev = head->next = head;
		} else {
			// insert before the 'head'
			DoubleNode *cur = new DoubleNode();
			cur->v = x;
			cur->prev = head->prev;
			cur->next = head;
			head->prev->next = cur;
			head->prev = cur;
			head = cur;
		}
	}

	void remove(int x) {
		if (head) {
			int first = 1;
			for (DoubleNode *cur = head; head && (first || cur != head); ) {
				if (cur->v != x) {
					cur = cur->next;
					first = 0;
				} else {
					if (cur->next == cur) {
						// The only one element will be deleted
						delete cur;
						head = cur = NULL;
					} else {
						if (cur == head) {
							head = cur->prev;
						}
						DoubleNode *nxt = cur->next;
						cur->prev->next = cur->next;
						cur->next->prev = cur->prev;
						delete cur;
						cur = nxt;
					}
				}
			}
		}		
	}

	// for debugging
	void show() {
		printf("Circular list : ");
		if (head) {
			int first = 1;
			for (DoubleNode *cur = head; first || cur != head; cur = cur->next, first = 0)
				printf("%d ", cur->v);
		}
		puts("");
	}
};

void test(int cas, int m) {
	int n, v, op;
	srand((unsigned)time(NULL));
	for (int ca = 1; ca <= cas; ++ca) {
		n = rand() % m + 1;
		LinkedList list;
		DoubleLinkedList dlist;
		CircularLinkedList clist;
		printf("\nCase %d:\n", ca);
		for (int o = 0; o < n; ++o) {
			op = rand() % 2;
			if (op == 0) {
				// insert
				printf("insert %d\n", v = rand() % m);
				list.insert(v);
				dlist.insertBeginning(v);
				clist.insert(v);
			} else {
				// remove
				printf("remove %d\n", v = rand() % m);
				list.remove(v);
				dlist.remove(v);
				clist.remove(v);
			}
			list.show();
			dlist.show();
			clist.show();
		}
	}	
}

int main() {
	test(10, 10);

	return 0;
}
