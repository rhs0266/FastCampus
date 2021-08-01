#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 32005

int K, n, m, indeg[NM], order[NM], maxCnt[NM];
vector<int> con[NM];

void input() {
	cin >> K >> n >> m;
	for (int i = 1; i <= n; i++) {
		indeg[i] = order[i] = 0;
		con[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		indeg[y]++;
	}
}

#include <queue>
void pro() {
	queue<int> Q;

	// 제일 앞에 "정렬될 수 있는" 정점 찾기
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) {
			Q.push(i);
			order[i] = 1;
			maxCnt[i] = 1;
		}

	int ans = 0;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		// 만약 들어오는 순서 중 가장 큰 순서가 2개 이상이면 자신의 순서를 1 증가시킨다.
		if (maxCnt[x] >= 2) order[x]++;
		ans = max(ans, order[x]);
		for (int y : con[x]) {
			indeg[y]--;
			if (indeg[y] == 0) Q.push(y);
			// Stahler 순서 계산을 위해서 y번 정점에 들어오는 최대 순서를 갱신해준다.
			if (order[y] == order[x]) maxCnt[y]++;
			else if (order[y] < order[x]) {
				order[y] = order[x];
				maxCnt[y] = 1;
			}
		}
	}
	cout << K << " " << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		input();
		pro();
	}
	return 0;
}