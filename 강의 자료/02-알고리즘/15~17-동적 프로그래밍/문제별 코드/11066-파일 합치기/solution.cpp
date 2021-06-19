#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

#include <vector>
int n, a[NM], dy[NM][2];
vector<int> con[NM];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
}
void dfs(int x, int par) {
	dy[x][1] = a[x];
	for (int y : con[x]) {
		if (y == par) continue;
		dfs(y, x);
		dy[x][0] += max(dy[y][0], dy[y][1]);
		dy[x][1] += dy[y][0];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	input();
	dfs(1, -1);
	cout << max(dy[1][0], dy[1][1]);
	return 0;
}