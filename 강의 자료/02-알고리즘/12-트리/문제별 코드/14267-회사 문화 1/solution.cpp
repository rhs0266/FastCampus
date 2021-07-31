#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005

int n, m;
int Dy[NM];
vector<int> children[NM];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int par;
		cin >> par;
		if (i == 1) continue;
		children[par].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		int x, v;
		cin >> x >> v;
		Dy[x] += v;
	}
}

// 내가 받은 칭찬을 부하 직원들에게 누적시켜주는 작업을 해주면 된다.
void DFS(int x) {
	for (int y : children[x]) {
		Dy[y] += Dy[x];
		DFS(y);
	}
}
void pro() {
	DFS(1);
	for (int i = 1; i <= n; i++) cout << Dy[i] << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}