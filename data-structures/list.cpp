#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

// Single-linked list

struct Node {
	int v;	// data
	Node *next;
};

class LinkedList {
	Node *head;
public:
	LinkedList() {
		head = new Node();
		head->next = NULL;
	}

	~LinkedList() {
		Node *pre = head;
		for (Node *cur = head->next; cur != NULL; cur = cur->next) {
			delete pre;
			pre = cur;
		}
		delete pre;
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

// @todo: Double-linked list
struct DoubleNode {
	int v;
	DoubleNode *pre;
	DoubleNode *nxt;
};

// @todo: sparse matrix operations with lists

void test(int cas, int m) {
	int n, v, op;
	srand((unsigned)time(NULL));
	for (int ca = 1; ca <= cas; ++ca) {
		n = rand() % m + 1;
		LinkedList list;
		printf("\nCase %d:\n", ca);
		for (int o = 0; o < n; ++o) {
			op = rand() % 2;
			if (op == 0) {
				// insert
				printf("insert %d\n", v = rand() % m);
				list.insert(v);
			} else {
				// remove
				printf("remove %d\n", v = rand() % m);
				list.remove(v);
			}
			list.show();
		}
	}	
}

int main() {
	test(10, 10);

	return 0;
}
