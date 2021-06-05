#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#include <vector>
vector<int> adj[105];
int n, m;
void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

bool visit[105];
#include <queue>
void BFS(int S) {
	for (int i = 1; i <= n; i++) visit[i] = false;
	queue<int> Q;
	Q.push(S), visit[S] = true;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int y : adj[x]) {
			if (visit[y]) continue;
			visit[y] = true;
			Q.push(y);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	BFS(1);
	int ans = 0;
	for (int i = 2; i <= n; i++)
		if (visit[i])
			ans++;
	cout << ans;
	return 0;
}