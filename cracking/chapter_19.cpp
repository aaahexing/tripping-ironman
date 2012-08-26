#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

// 19.1: swap two numbers without temporary variables
inline void swapIt(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

// 19.2: trailing zeros in n factorial
int countZero(int n) {
	int ret = 0;
	for (; n; n /= 5) {
		ret += n / 5;
	}
	return ret;
}

// 19.4: implement max without any if-else or comparison operators
int getMax(int a, int b) {
	int c = a - b;
	int k = (c >> 31) & 0x1;
	return a - k * c;
}

// 19.9: translate integer to English phrase
const char a[][MAXN] = {
	"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
	"Eleven", "Tweleve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};
const char b[][MAXN] = {
	"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};
vector<string> trans(int n) {
	vector<string> s;
	if (n == 0) {
		s.push_back("Zero");
	} else {
		if (n >= 1000) {
			vector<string> th = trans(n / 1000);
			s.insert(s.end(), th.begin(), th.end());
			s.push_back("Thousand,");
			n %= 1000;
		}
		if (n >= 100) {
			s.push_back(a[n / 100]);
			s.push_back("Hundred");
			n %= 100;
		}
		if (n > 0) {
			if (!s.empty()) {
				s.push_back("and");			
			}
			if (n < 20) {
				s.push_back(a[n]);
			} else {
				s.push_back(b[n / 10]);
				if (n % 10 > 0) {
					s.push_back(a[n % 10]);
				}
			}	
		}
	}
	return s;
}

int main() {
	int n, a, b;
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			scanf("%d%d", &a, &b);
			swapIt(a, b);
			printf("swap : %d %d\n", a, b);
		} else if (n == 2) {
			scanf("%d", &n);
			printf("zeros : %d\n", countZero(n));
		} else if (n == 9) {
			scanf("%d", &n);
			vector<string> res = trans(n);
			printf("trans :");
			for (int i = 0; i < (int)res.size(); ++i) {
				if (i) putchar(' ');
				printf("%s", res[i].c_str());
			}
			puts("");
		}
	}
	return 0;
}
