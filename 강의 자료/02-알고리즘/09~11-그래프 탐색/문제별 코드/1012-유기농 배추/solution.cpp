#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 55

int N, M, K;
int a[NM][NM];

void input() {
	cin >> M >> N >> K;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) a[i][j] = 0;
	for (int i = 1; i <= K; i++) {
		int x, y;
		cin >> y >> x;
		x++, y++;
		a[x][y] = 1;
	}
}

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool visit[NM][NM];

// x, y 를 갈 수 있다는 걸 알고 방문한 상태
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dir[k][0];
		int ny = y + dir[k][1];
		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;  // 지도를 벗어나는 곳으로 가는가?
		if (a[nx][ny] == 0) continue;  // 갈 수 있는 칸인지 확인해야 한다.
		if (visit[nx][ny]) continue;  // 이미 방문한 적이 있는 곳인가?
		dfs(nx, ny);
	}
}
void pro() {
	int ans = 0;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) visit[i][j] = false;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (a[i][j] == 1 && !visit[i][j]) {
				ans++;
				dfs(i, j);
			}
	cout << ans << "\n";
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		input();
		pro();
	}
	return 0;
}