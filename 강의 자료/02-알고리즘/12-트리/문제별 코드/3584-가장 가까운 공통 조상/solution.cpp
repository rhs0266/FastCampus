#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 10005

int n, par[NM], check[NM], TT;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) par[i] = 0;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		par[v] = u;
	}
}

void pro() {
	int x, y;
	cin >> x >> y;
    // x 에서 루트까지 체크를 해놓는다.
	while (x) check[x] = TT, x = par[x];

    // y 에서 루트로 이동하면서 처음으로 만나는 체크된 정점을 찾는다.
	while (y && check[y] != TT) y = par[y];
    
	cout << y << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	for (TT = 1; TT <= T; TT++) {
		input();
		pro();
	}
	return 0;
}