#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 30

int N;
char a[NM][NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
		}
	}
}

#include <queue>
queue<int> Q;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, group_cnt;
bool visit[NM][NM];

// x, y 를 갈 수 있다는 걸 알고 방문한 상태
void dfs(int x, int y) {
	group_cnt++;
	visit[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dir[k][0];
		int ny = y + dir[k][1];
		if (nx < 1 || ny < 1 || nx > N || ny > N) continue;  // 지도를 벗어나는 곳으로 가는가?
		if (a[nx][ny] == '0') continue;  // 갈 수 있는 칸인지 확인해야 한다.
		if (visit[nx][ny]) continue;  // 이미 방문한 적이 있는 곳인가?
		dfs(nx, ny);
	}
}
void pro() {
	vector<int> groups;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (a[i][j] == '1' && !visit[i][j]) {
				group_cnt = 0;
				dfs(i, j);
				groups.push_back(group_cnt);
			}
	sort(groups.begin(), groups.end());
	cout << groups.size() << '\n';
	for (int g : groups) cout << g << '\n';
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}