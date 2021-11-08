#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 105

int N, M, H, dist[NM][NM][NM], a[NM][NM][NM];
int dir[6][3] = { {1,0,0,},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1}, {0,0,-1} };
int sx, sy, ex, ey;

void input() {
    cin >> M >> N >> H;
    for (int h = 1; h <= H; h++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> a[h][i][j];
            }
        }
    }
}

#include <queue>
void bfs() {
    queue<int> Q;
    for (int h = 1; h <= H; h++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dist[h][i][j] = -1;
                if (a[h][i][j] == 1) {
                    dist[h][i][j] = 0;
                    Q.push(h); Q.push(i); Q.push(j);
                }
            }
        }
    }
    while (!Q.empty()) {
        int h = Q.front(); Q.pop();
        int i = Q.front(); Q.pop();
        int j = Q.front(); Q.pop();
        for (int k = 0; k < 6; k++) {
            int nh = h + dir[k][0];
            int ni = i + dir[k][1];
            int nj = j + dir[k][2];
            if (nh < 1 || ni < 1 || nj < 1 || nh > H || ni > N || nj > M) continue;
            if (dist[nh][ni][nj] != -1) continue;
            if (a[nh][ni][nj] == -1) continue;
            dist[nh][ni][nj] = dist[h][i][j] + 1;
            Q.push(nh); Q.push(ni); Q.push(nj);
        }
    }
}
void pro() {
    bfs();
    int ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (a[h][i][j] == -1) continue;
                if (dist[h][i][j] == -1) {
                    cout << -1;
                    return;
                }
                ans = max(ans, dist[h][i][j]);
            }
        }
    }
    cout << ans;

}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    pro();
    return 0;
}