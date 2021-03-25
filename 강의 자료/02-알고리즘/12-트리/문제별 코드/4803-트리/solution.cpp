#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;

#define NM 505

#include <vector>
int n, m;
vector<int> con[NM];
int visit[NM];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) con[i].clear();
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
}

int v_cnt = 0, edge_cnt = 0;
void dfs(int x) {
	visit[x] = 1;
	v_cnt++;
	edge_cnt += con[x].size();
	for (int y : con[x]) {
		if (visit[y]) continue;
		dfs(y);
	}
}

void pro() {
	for (int i = 1; i <= n; i++) visit[i] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1) continue;
		v_cnt = 0;
		edge_cnt = 0;
		dfs(i);
		if (2 * (v_cnt - 1) == edge_cnt) ans++;
	}
	if (ans == 0) cout << "No trees.\n";
	if (ans == 1) cout << "There is one tree.\n";
	if (ans >= 2) cout << "A forest of " << ans << " trees.\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int t=1;;t++) {
		input();
		if (n == 0 && m == 0) break;
		cout << "Case " << t << ": ";
		pro();
	}
	return 0;
}