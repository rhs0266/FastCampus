#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 305

int N, dist[NM][NM];
int dir[8][2] = { {-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1},{1,2},{2,1} };
int sx, sy, ex, ey;

void input() {
    cin >> N >> sx >> sy >> ex >> ey;
}

#include <queue>
int bfs() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = -1;
        }
    }
    queue<int> Q;
    Q.push(sx); Q.push(sy);
    dist[sx][sy] = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        int y = Q.front(); Q.pop();
        for (int k = 0; k < 8; k++) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push(nx); Q.push(ny);
        }
    }
    return dist[ex][ey];
}
void pro() {
    cout << bfs() << "\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int TT; cin >> TT;
    while (TT--) {
        input();
        pro();
    }
    return 0;
}