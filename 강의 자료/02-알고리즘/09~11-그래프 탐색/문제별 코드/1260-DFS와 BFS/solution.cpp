#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#include <vector>
vector<int> adj[1005];
int n, m, V;
void input() {
	cin >> n >> m >> V;
	for (int i = 1;i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
}

int visit[1005], dist[1005];

void DFS(int x) {
	cout << x << " ";
	visit[x] = true;
	for (int y : adj[x]) {
		if (visit[y]) continue;
		DFS(y);
	}
}

#include <queue>
void BFS(int S) {
	for (int i = 1; i <= n; i++) visit[i] = dist[i] = 0;
	queue<int> Q;
	Q.push(S), visit[S] = 1, dist[S] = 0;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		cout << x << " ";
		for (int y : adj[x]) {
			if (visit[y]) continue;
			visit[y] = 1;
			dist[y] = dist[x] + 1;
			Q.push(y);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	DFS(V);
	cout << "\n";
	BFS(V);
	return 0;
}