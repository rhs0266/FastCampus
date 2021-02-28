#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 105

int n, m;
char a[NM][NM];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
}

#include <queue>
int dist[NM][NM];
queue<int> Q;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void pro() {
	Q.push(1); Q.push(1);
	dist[1][1] = 1;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		int y = Q.front(); Q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dir[k][0];
			int ny = y + dir[k][1];
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (a[nx][ny] == '0') continue;
			if (dist[nx][ny] != 0) continue;
			dist[nx][ny] = dist[x][y] + 1;
			Q.push(nx); Q.push(ny);
		}
	}
	cout << dist[n][m];
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}