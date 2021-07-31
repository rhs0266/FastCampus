#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 1000005

#include <vector>
int n, Q, estate[NM];

void input() {
	cin >> n >> Q;
}

void pro() {
	// 사고 싶은 땅에서 시작해서 루트 땅까지 올라오면서 정답을 찾으면 편하다.
	// 왜냐하면 부모 노드는 찾기 쉽기 때문이다.
	while (Q--) {
		int x, y, res = 0;
		cin >> x;
		y = x;
		while (x) {
			if (estate[x]) res = x;
			x >>= 1;
		}
		estate[y] = 1;
		cout << res << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}