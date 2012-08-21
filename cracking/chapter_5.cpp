#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// 5.1
inline int set(int n, int m, int i, int j) {
	int mask = (1 << (j + 1)) - (1 << i);
	n &= ~(n & mask);
	n |= (m & mask);
	return n;
}

// 5.2: error when f cannot be represented by 32 bits
inline string rep(float f) {
	string s = "";
	for (int n = (int)f; n > 0; ) {
		s += '0' + (n & 1);
		n >>= 1;
	}
	reverse(s.begin(), s.end());
	if (s == "") {
		s = "0";
	}
	s += ".";
	for(f -= (int)f; f > 0; ) {
		s += '0' + (int)(f * 2.f);
		f = (f * 2.f) - (int)(f * 2.f);
	}
	return s;
}

inline void nextRep(string s) {
	// next smallest
	string s0 = "0" + s;
	for (int i = (int)s0.length() - 1; i >= 0; --i) {
		if (s0[i] == '1') {
			for (int j = i - 1; j >= 0; --j) {
				if (s0[j] == '0') {
					s0[j] = '1';
					s0[j + 1] = '0';
					int c1 = 0;
					for (int k = j + 2; k < (int)s0.length(); ++k) {
						c1 += (s0[k] == '1');
					}
					for (int k = j + 2; k < (int)s0.length() - c1; ++k) {
						s0[k] = '0';
					}
					for (int k = (int)s0.length() - c1; k < (int)s0.length(); ++k) {
						s0[k] = '1';
					}
					break;
				}
			}
			break;
		}
	}
	while (s0.length() > 1 && s0[0] == '0') {
		s0 = s0.substr(1);
	}
	cout << "s0 = " << s0 << endl;
	// prev biggest
	string s1 = "0" + s;
	for (int i = (int)s1.length(); i >= 0; --i) {
		if (s1[i] == '0') {
			for (int j = i - 1; j >= 0; --j) {
				if (s1[j] == '1') {
					s1[j] = '0';
					s1[j + 1] = '1';
					int c1 = 0;
					for (int k = j + 2; k < (int)s1.length(); ++k) {
						c1 += (s1[k] == '1');
					}
					for (int k = j + 2; k < j + 2 + c1; ++k) {
						s1[k] = '1';
					}
					for (int k = j + 2 + c1; k < (int)s1.length(); ++k) {
						s1[k] = '0';
					}
					break;
				}
			}
			break;
		}
	}
	while (s1.length() > 1 && s1[0] == '0') {
		s1 = s1.substr(1);
	}
	cout << "s1 = " << s1 << endl;
}

int main() {
	int n;
	float f;
	string s;
	while (cin >> n) {
		if (n == 2) {
			cin >> f;
			cout << rep(f) << endl;
		} else if (n == 3) {
			cin >> s;
			nextRep(s);
		}
	}
	return 0;
}
