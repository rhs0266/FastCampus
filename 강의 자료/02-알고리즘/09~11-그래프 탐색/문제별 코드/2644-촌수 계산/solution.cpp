#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 105

#include <vector>
vector<int> adj[NM];
int n, m, st, ed, dist[NM];
void input() {
	cin >> n;
	cin >> st >> ed;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

#include <queue>
void BFS(int S) {
	for (int i = 1; i <= n; i++) dist[i] = -1;
	queue<int> Q;
	Q.push(S), dist[S] = 0;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int y : adj[x]) {
			if (dist[y] != -1) continue;
			dist[y] = dist[x] + 1;
			Q.push(y);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	BFS(st);
	cout << dist[ed];
	return 0;
}