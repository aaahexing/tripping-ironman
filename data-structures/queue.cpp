#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// Queue

struct Node {
	int v;
	Node *prev;
	Node *next;
};

class Queue {
	Node *head;	// empty node
	Node *tail;	// empty node
public:
	Queue() {
		head = new Node();
		tail = new Node();
		head->v = 0;
		head->prev = NULL;
		head->next = tail;
		tail->v = 0;
		tail->prev = head;
		tail->next = NULL;
	}

	~Queue() {
		Node *pre = head;
		for (Node *cur = pre->next; cur != NULL; cur = pre->next) {
			delete pre;
			pre = cur;
		}
		delete pre;
		head = tail = NULL;
	}

	inline bool empty() const {
		return head->next == tail;
	}

	inline Node* front() {
		return head->next;
	}

	inline void push(int x) {
		Node *cur = new Node();
		cur->v = x;
		cur->next = tail;
		cur->prev = tail->prev;
		tail->prev->next = cur;
		tail->prev = cur;
	}

	inline void pop() {
		Node *pre = head->next->next;
		delete head->next;
		head->next = pre;
	}
};

struct SingleNode {
	int v;
	unsigned ptr_mask;
};

class SingleQueue {
	SingleNode *head;	// empty node
	SingleNode *tail;	// empty node
public:
	SingleQueue() {
		head = new SingleNode();
		tail = new SingleNode();
		head->v = 0;
		head->ptr_mask = (unsigned)tail;
		tail->v = 0;
		tail->ptr_mask = (unsigned)head;
	}

	~SingleQueue() {
		SingleNode *pre = head;
		for (SingleNode *cur = (SingleNode*)(pre->ptr_mask ^ 0); cur != NULL; cur = (SingleNode*)(pre->ptr_mask ^ (unsigned)cur)) {
			delete pre;
			pre = cur;
		}
		delete pre;
		head = tail = NULL;
	}

	inline bool empty() const {
		return (SingleNode*)(head->ptr_mask ^ 0) == tail;
	}

	inline SingleNode* front() {
		return (SingleNode*)(head->ptr_mask ^ 0);
	}

	inline void push(int x) {
		// @todo: not implemented
	}

	inline void pop() {
		// @todo: not implemented
	}
};

int main() {
	int n, v;
	char cmd[16];
	
	while (scanf("%d", &n) != EOF) {
		Queue Q;
		for (int i = 0; i < n; ++i) {
			scanf("%s", cmd);
			if (!strcmp(cmd, "pop")) {
				if (!Q.empty()) {
					Q.pop();				
				}
			} else if (!strcmp(cmd, "push")) {
				scanf("%d", &v);
				Q.push(v);
			}
			if (Q.empty()) {
				puts("empty queue");
			} else {
				printf("Q.front = %d\n", Q.front()->v);
			}
		}
	}
	return 0;
}

