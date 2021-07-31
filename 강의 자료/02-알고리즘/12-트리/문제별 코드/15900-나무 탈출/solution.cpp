#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 500005

#include <vector>
int n;
vector<int> con[NM];

void input() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
}

// 모든 leaf node 들의 깊이의 합이 짝수냐 홀수냐가 승리 요건
// sum_leaf_depth: 모든 leaf node 들의 깊이의 합
int sum_leaf_depth;
void dfs(int x, int prev, int depth) {
	if (x != 1 && con[x].size() == 1) sum_leaf_depth += depth;
	for (int y : con[x]) {
		if (y == prev) continue;
		dfs(y, x, depth + 1);
	}
}

void pro() {
	dfs(1, -1, 0);
	if (sum_leaf_depth % 2 == 0) cout << "No";
	else cout << "Yes";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}