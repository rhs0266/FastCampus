#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 300

int N, M;
char a[NM][NM];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> a[i][j];
		}
	}
}

int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, totalSheep, totalWolf;
bool visit[NM][NM];

int sheep, wolf;
// x, y 를 갈 수 있다는 걸 알고 방문한 상태
void dfs(int x, int y) {
	if (a[x][y] == 'o') sheep++;
	if (a[x][y] == 'v') wolf++;
	visit[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dir[k][0];
		int ny = y + dir[k][1];
		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;  // 지도를 벗어나는 곳으로 가는가?
		if (a[nx][ny] == '#') continue;  // 갈 수 있는 칸인지 확인해야 한다.
		if (visit[nx][ny]) continue;  // 이미 방문한 적이 있는 곳인가?
		dfs(nx, ny);
	}
}
void pro() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (a[i][j] != '#' && !visit[i][j]) {
				sheep = wolf = 0;
				dfs(i, j);
				if (sheep > wolf) totalSheep += sheep;
                else totalWolf += wolf;
			}
	cout << totalSheep << " " << totalWolf;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}