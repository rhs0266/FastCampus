#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#include <vector>
vector<int> adj[1005];
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

bool visit[1005];

void DFS(int x) {
	visit[x] = true;
	for (int y : adj[x]) {
		if (visit[y]) continue;
		DFS(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		ans++;
		DFS(i);
	}
	cout << ans;
	return 0;
}