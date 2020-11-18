#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define INF 0x7fffffff
#define NM 100005

using namespace std;

int n, m, A, B;
ll money;
struct Edge {
	int v, cost;
};
vector<Edge> con[NM];

void input() {
	cin >> n >> m >> A >> B >> money;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		con[u].push_back({ v, c });
		con[v].push_back({ u, c });
	}
}

#include <queue>
ll dist[NM];
bool dijkstra(int limit) {
	priority_queue<pair<ll, int>> pq;
	for (int i = 1; i <= n; i++) dist[i] = money + 1;
	pq.push({ 0, A });
	dist[A] = 0;
	while (!pq.empty()) {
		auto [d, x] = pq.top(); pq.pop();
		d = -d;
		if (dist[x] != d) continue;
		for (auto [y, c] : con[x]) {
			if (d + c >= dist[y]) continue;
			if (c > limit) continue;
			dist[y] = d + c;
			pq.push({ -dist[y], y });
		}
	}
	return dist[B] <= money;
}

void pro() {
	int low = 1, high = 1e9, mid;
	ll ans = 1e10;
	while (low <= high) {
		mid = (low + high) / 2;
		if (dijkstra(mid)) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}
	if (ans == 1e10) ans = -1;
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}