#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 505

#include <vector>
vector<int> adj[NM];
int n, m, dist[NM];
void input() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

#include <queue>
int BFS(int S) {
	int ret = 0;
	for (int i = 1; i <= n; i++) dist[i] = -1;
	queue<int> Q;
	Q.push(S), dist[S] = 0;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		if (1 <= dist[x] && dist[x] <= 2) ret++;
		if (dist[x] == 2) continue;
		for (int y : adj[x]) {
			if (dist[y] != -1) continue;
			dist[y] = dist[x] + 1;
			Q.push(y);
		}
	}
	return ret;
}

void pro(){
	cout << BFS(1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}