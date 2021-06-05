#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#include <vector>
int adj[105][105];
int n, m;
void input() {
	cin >> n;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			cin >> adj[i][j];
		}
	}
}

bool visit[105];
#include <queue>
void BFS(int S) {
	for (int i = 1; i <= n; i++) visit[i] = false;
	queue<int> Q;
	Q.push(S);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int y = 1; y <= n; y++){
			if (adj[x][y] == 0 || visit[y]) continue;
			visit[y] = true;
			Q.push(y);
		}
	}
	for (int i = 1; i <= n; i++){
		cout << (visit[i] ? 1 : 0) << " ";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	for (int i = 1; i <= n; i++)
		BFS(i);
	return 0;
}