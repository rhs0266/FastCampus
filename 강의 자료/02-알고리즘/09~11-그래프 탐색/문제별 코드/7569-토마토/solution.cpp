#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 1005

int N, M, a[NM][NM], dist[NM][NM];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input() {
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }
}

#include <queue>
int bfs() {
    queue<int> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dist[i][j] = -1;
            if (a[i][j] == 1) {
                dist[i][j] = 0;
                Q.push(i); Q.push(j);
            }
        }
    }
    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        int j = Q.front(); Q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if (ni < 1 || nj < 1 || ni > N || nj > M) continue;
            if (dist[ni][nj] != -1) continue;
            if (a[ni][nj] == -1) continue;
            dist[ni][nj] = dist[i][j] + 1;
            Q.push(ni); Q.push(nj);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (a[i][j] == -1) continue;
            if (dist[i][j] == -1) return -1;
            ans = max(ans, dist[i][j]);
        }
    }
    return ans;
}
void pro() {
    cout << bfs();
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    pro();
    return 0;
}