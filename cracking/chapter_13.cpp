#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

// 13.1
char s[MAXN][MAXN];
void lastKLines(const char *filename, int K) {
	FILE *reader = fopen(filename, "r");
	if (reader == NULL) {
		fprintf(stderr, "Failed to read file '%s'!\n", filename);
		return;
	}
	int lines = 0;
	for (; fgets(s[lines % K], MAXN, reader) != NULL; ++lines);
	int start = 0, num = lines;
	if (lines >= K) {
		start = lines % K;
		num = K;
	}
	for (int i = 0; i < num; ++i) {
		printf("%s\n", s[start + i]);
	}
	fclose(reader);
}

// 13.6: name hiding
class FirstClass {
public:
	virtual void gao(int);
	virtual void gao(int, int);
};

void FirstClass::gao(int) {
	puts("ONE");
}

void FirstClass::gao(int, int) {
	puts("TWO");
}

class SecondClass : public FirstClass {
public:
	// @note: name will be hided not only when the method is overloaded.
	void gao(int, int, int);
};

void SecondClass::gao(int, int, int) {
	puts("Three");
}

// 13.9: reference counting
//		a. Make every object inherit from a common base class with count-vars
//		b. Create a smart pointer class to handle assignment and copy constructors properly (inc or dec the counter)
//		c. Remember to delete the obj when ref-count == 0 and rember to dec the counter in a copy-assignment.
class Referenced {
	int cc;
public:
	Referenced() {
		cc = 1;
	}

	void incRefCount() {
		++cc;
	}

	int decRefCount() {
		return --cc;
	}
};

// Smart pointer
template<typename T>
class ReferenceToObj {
	T *obj;
	void decRef() {
		if (obj && obj->decRefCount() == 0) {
			delete obj;
			obj = NULL;
		}
	}
public:
	class NullReference {
	
	};

	ReferenceToObj(T *_obj = NULL)
		: obj(_obj) {}
	
	ReferenceToObj(ReferenceToObj<T> &orig) {
		obj = orig.obj;
		if (obj) {
			obj->incRefCount();
		}
	}

	~ReferenceToObj() {
		decRef();
	}

	T& operator* () throw (NullReference) {
		if (obj == NULL) {
			return NullReference();
		} else {
			return *obj;
		}
	}

	T* operator-> () throw (NullReference) {
		if (obj == NULL) {
			return NullReference();
		} else {
			return obj;
		}
	}

	ReferenceToObj<T>& operator= (ReferenceToObj<T> &ref) {
		if (this == &ref) {
			return *this;
		}
		if (ref.obj) {
			ref.obj->incRefCount();
		}
		decRef();
		obj = ref.obj;
		return *this;
	}
};

class Buffer : public Referenced {
public:
	Buffer() {
		puts("--] Buffer created");
	}

	~Buffer() {
		puts("--] Buffer destroyed");
	}
};

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 6) {
			FirstClass a;
			a.gao(1);
			a.gao(1, 1);
			SecondClass b;
			// b.gao(1);
			// b.gao(1, 1);
			b.gao(1, 1, 1);
		} else if (n == 9) {
			ReferenceToObj<Buffer> ref(new Buffer());
			ReferenceToObj<Buffer> another_ref = ref;
		}
	}
	return 0;
}

