#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (A[i - 1] > B[j - 1]) {
                A[i + j - 1] = A[--i];
            } else {
                A[i + j - 1] = B[--j];
            }
        }
        while (i > 0) {
            A[i + j - 1] = A[--i];
        }
        while (j > 0) {
            A[i + j - 1] = B[--j];
        }
    }
};

int main() {
	Solution s;
	int a0[10] = {1, 3, 5, 6};
	int b0[10] = {1, 2, 4};
	s.merge(a0, 4, b0, 3);
	return 0;
}
