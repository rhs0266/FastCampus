#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 55

int N;

struct Elem {
	int num, idx;
	bool operator<(const Elem& rhs) const {
		if (num != rhs.num) return num < rhs.num;
		return idx < rhs.idx;
	}
}B[NM];
int P[NM];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		B[i] = { x, i };
	}
}

void pro() {
	sort(B, B + N);
	for (int i = 0; i < N; i++) {
		P[B[i].idx] = i;
	}
	for (int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}