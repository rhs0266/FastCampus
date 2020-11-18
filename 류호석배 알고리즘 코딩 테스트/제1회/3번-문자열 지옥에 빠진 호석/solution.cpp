#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
#define NM 15
#define INF 0x7fffffff

int n, m, K;
char a[NM][NM], target[10005][NM];
void input() {
	cin >> n >> m >> K;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= K; i++) {
		cin >> target[i];
	}
}

#include <string>
#include <unordered_map>
#include <map>
unordered_map<string, int> mem;

int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
int ans[10005];
void dfs(int i, int j, string path,int len) {
	mem[path]++;
	if (len == 5) return;
	for (int k = 0; k < 8; k++) {
		int ni = (i + dir[k][0]) % n;
		int nj = (j + dir[k][1]) % m;
		if (ni < 0) ni += n;
		if (nj < 0) nj += m;

		dfs(ni, nj, path + a[ni][nj], len+1);
	}
}

void pro() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, string(1, a[i][j]), 1);
		}
	}
	for (int i = 1; i <= K; i++) {
		cout << mem[string(target[i])] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}