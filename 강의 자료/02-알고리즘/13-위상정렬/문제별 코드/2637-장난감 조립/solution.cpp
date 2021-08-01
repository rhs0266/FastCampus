#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 105

int n, m, indeg[NM];
vector<pair<int, int> > con[NM];
int cnt[NM][NM];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		cin >> y >> x >> v;
		con[x].push_back({y, v});
		indeg[y]++;
	}
}

#include <queue>
void pro() {
	queue<int> Q;

	// 기본 부품 찾기
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0){
			Q.push(i);
			cnt[i][i] = 1;
		}

	// 먼저 만들 수 있는 제품들부터 차례대로 만들어서 필요 기본 부품 개수 계산하기
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (auto p : con[x]) {
			auto [y, v] = p;
			indeg[y]--;

			// 제품 y에 제품 x 가 v 개 필요하므로 기본 부품 개수에 v 를 곱해서 누적시켜 준다.
			for (int i = 1; i <= n; i++)
				cnt[y][i] += cnt[x][i] * v;
			if (indeg[y] == 0) Q.push(y);
		}
	}
	for (int i = 1; i <= n; i++)
		if (cnt[n][i] != 0)
			cout << i << " " << cnt[n][i] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}