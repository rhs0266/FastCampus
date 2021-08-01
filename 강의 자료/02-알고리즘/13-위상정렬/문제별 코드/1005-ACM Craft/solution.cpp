#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005

int n, m, indeg[NM], T[NM], T_done[NM];
vector<int> con[NM];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> T[i];
		T_done[i] = 0;
		indeg[i] = 0;
		con[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		// indegree 계산하기
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
			T_done[i] = T[i];
		}

	// 위상 정렬 순서대로 T_done 계산을 함께 해주기
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int y : con[x]) {
			indeg[y]--;
			if (indeg[y] == 0) Q.push(y);
			T_done[y] = max(T_done[y], T_done[x] + T[y]);
		}
	}

	int W;
	cin >> W;
	cout << T_done[W] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		input();
		pro();
	}
	return 0;
}