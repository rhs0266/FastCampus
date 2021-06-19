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
void DFS(int x, int par) {
	for (int y: adj[x]){
		if (y == par) continue;
		parent[y] = x;
		DFS(y, x);
	}
}

void pro(){
	DFS(1, -1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}