#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;

template <typename T>
class Wrapper {
	T* ptr;
public:
	Wrapper(T* _ptr) : ptr(_ptr) {
	}

	~Wrapper() {
		delete ptr;
		ptr = NULL;
	}

	T* operator->() {
		return ptr;
	}
};

template <typename T>
class RefCounted {
	T *ptr;
	unsigned *count;
private:
	inline unsigned addRef() {
		return ++count;
	}
	inline unsigned decRef() {
		return --count;
	}
public:
	RefCounted() {
		count = new unsigned(0);
		addRef();
	}

	RefCounted(T *_ptr) {
		ptr = _ptr;
		count = new unsigned(0);
		addRef();
	}

	RefCounted(const RefCounted<T> &rf) {
		ptr = rf.ptr;
		count = rf.count;
		addRef();
	}

	~RefCounted() {
		if (decRef() == 0) {
			delete ptr;
			ptr = NULL;
			delete count;
			count = NULL;
		}
	}

	RefCounted<T>& operator= (const RefCounted<T> &rf) {
		if (this != &rf) {
			if (decRef() == 0) {
				delete ptr;
				delete count;
			}
			ptr = rf.ptr;
			count = rf.count;
			addRef();
		}
		return *this;
	}

	T& operator* () {
		return *ptr;
	}

	T* operator-> () {
		return ptr;
	}
};

// Test it
class Thing {
	int a, b;
public:
	Thing(int _a = 10, int _b = 20) : a(_a), b(_b) {
	}

	~Thing() {
		puts("destructor called!");
	}
};

int main() {
	Thing *pThing = new Thing(11, 22);
	Wrapper<Thing> wThing(pThing);

	return 0;
}
