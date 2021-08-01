#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005

int n, m, indeg[NM];
vector<int> con[NM];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int cnt, x, y;
		cin >> cnt;
		cin >> x;
        // A1, A2, ... Acnt 순서로 나가야 한다면,
        // A1 -> A2
        // A2 -> A3
        // ...
        // A(cnt-1) -> Acnt
        // 의 간선을 만들어주면 된다.
		for (int j = 2; j <= cnt; j++) {
			cin >> y;
			con[x].push_back(y);
			indeg[y]++;
			x = y;
		}
	}
}

#include <queue>
void pro() {
	queue<int> Q;

	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) {
			Q.push(i);
		}

	vector<int> ans;
    // 우선순위에 대한 조건을 간선으로 표현했으므로 위상정렬을 수행하면 된다.
	while (!Q.empty()) {
		int x = Q.front();
		ans.push_back(x);
		Q.pop();
		for (int y : con[x]) {
			indeg[y]--;
			if (indeg[y] == 0) Q.push(y);
		}
	}
	if (ans.size() != n) cout << 0;
	else for (int x : ans) cout << x << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}