#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 16.5: find whether a machine is big endian or little endian
int testByteOrder() {
	short word = 0x0001;
	char *byte = (char*)&word;
	return (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

// 16.9: aligned malloc and aligned free, alignment is power of two
void* alignedMalloc(size_t required_bytes, size_t alignment) {
	void *p1 = NULL;	// original block
	void **p2 = NULL;	// aligned block
	int offset = alignment - 1 - sizeof(void*);
	if ((p1 = (void*)malloc(required_bytes + offset)) == NULL) {
		return NULL;
	}
	p2 = (void**)(((size_t)p1 + offset) & ~(alignment - 1));
	p2[-1] = p1;
	return p2;
}

void aligned_free(void *p) {
	free(((void**)p)[-1]);
}

// 16.10: allocates a two dimensional array, minimize the number of calls to malloc
//	and make the memory is accessible by notation arr[i][j]
int** my2DAlloc(int row, int col) {
	int header = row * sizeof(int*);
	int data = row * col * sizeof(int);
	int **row_ptr = (int**)malloc(header + data);
	int *data_ptr = (int*)(row_ptr + row);
	for (int k = 0; k < row; ++k) {
		row_ptr[k] = data_ptr + k * col;
	}
	return row_ptr;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 5) {
			printf("%s\n", testByteOrder() == BIG_ENDIAN ? "Big Endian" : "Little Endian");
		}
	}
	return 0;
}
