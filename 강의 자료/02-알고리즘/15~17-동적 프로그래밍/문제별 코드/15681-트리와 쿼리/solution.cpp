#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005

int n, R, Q;
int Dy[NM];
vector<int> con[NM];

void input() {
	cin >> n >> R >> Q;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
}

// Dy[x] 를 계산하는 함수
void DFS(int x, int prev) {
	Dy[x] = 1;
	for (int y : con[x]) {
		if (y == prev) continue;
		DFS(y, x);
		Dy[x] += Dy[y];
	}
}
void pro() {
	DFS(R, -1);
	while (Q--) {
		int x; cin >> x;
		cout << Dy[x] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}