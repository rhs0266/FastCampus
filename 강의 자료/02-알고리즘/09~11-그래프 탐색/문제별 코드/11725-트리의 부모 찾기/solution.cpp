#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005

#include <vector>
vector<int> adj[NM];
int n, m, parent[NM];
void input() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

bool visit[NM];
#include <queue>
void BFS(int S) {
	for (int i = 1; i <= n; i++) visit[i] = false;
	queue<int> Q;
	Q.push(S), visit[S] = true;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int y : adj[x]) {
			if (visit[y]) continue;
			parent[y] = x;
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
		cout << parent[i] << '\n';
	return 0;
}