#include <iostream>
#include <algorithm>
#include <string>
#define NM 505
#define INF 0x7fffffff
#define vi vector<int>
FILE* in = stdin, * out = stdout;
using namespace std;

unsigned long long int X = (1ull << 63) - 1;
string repA, repB;
inline int conv(char x) {
	if ('0' <= x && x <= '9') return x - '0';
	return x - 'a' + 10;
}
long long int possible(string str, int base) {
	long long int res = 0;
	for (char c : str) {
		if (conv(c) >= base) return -1;
		if (res > (X - conv(c)) / base) return -1;
		res = res * base + conv(c);
	}
	return res;
}
void input() {
	cin >> repA >> repB;
}
void pro() {
	long long int ansVal = -1, ansA, ansB;
	for (int A = 2; A <= 36; A++) {
		long long int valA = possible(repA, A);
		if (valA == -1) continue;
		for (int B = 2; B <= 36; B++) {
			if (A == B) continue;
			long long int valB = possible(repB, B);
			if (valB == -1) continue;
			if (valA != valB) continue;
			if (ansVal == -1) {
				ansVal = valA;
				ansA = A;
				ansB = B;
			}
			else {
				cout << "Multiple";
				return;
			}
		}
	}
	if (ansVal == -1) {
		cout << "Impossible";
		return;
	}
	cout << ansVal << " " << ansA << " " << ansB;
}
int main() {
	input();
	pro();
	return 0;
}