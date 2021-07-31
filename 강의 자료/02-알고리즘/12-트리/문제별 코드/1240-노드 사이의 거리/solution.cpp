#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005

int n, m;
vector<pair<int, int>> con[NM];

void input() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		con[u].push_back({ v, c });
		con[v].push_back({ u, c });
	}
}

int ans = 0;
// 현재 x 에 있으며, 부모 노드는 prev 이며, 목표 지점은 goal,
// 그리고 root부터 지금까지 이동 거리가 dist 이다.
void DFS(int x, int prev, int goal, int dist) {
	if (x == goal) {
		ans = dist;
		return;
	}
	for (auto& p : con[x]) {
		auto [y, c] = p;
		if (y == prev) continue;
		DFS(y, x, goal, dist + c);
	}
}

#include <queue>
void pro() {
	// 세 가지 풀이가 가능하다.
	// 1. 트리도 일종의 그래프이므로 최단거리 알고리즘인 Dijkstra 사용
	// 2. 트리에서 두 노드 사이의 경로는 유일한 점을 활용해서 BFS 사용
	// 3. 트리를 Rooted 트리로 변환해서 구현이 짧은 DFS를 통해 거리 계산하기.
	//    마찬가지로 두 노드 사이의 경로가 유일함을 확인한다.

	// 본 풀이는 3 번 접근을 다룬다.

	int x, y;
	cin >> x >> y;
	DFS(x, -1, y, 0);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	while (m--) {
		pro();
	}
	return 0;
}