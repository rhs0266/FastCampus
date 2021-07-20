#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
#define NM 105
#define INF 0x7fffffff

int n, m, a[NM][NM], dist[NM][NM][3];
int sx, sy, ex, ey;
struct Elem {
    int x, y, move, cost;

    Elem() {}

    Elem(int x, int y, int move, int cost) : x(x), y(y), move(move), cost(cost) {}

    bool operator<(const Elem& ot) const {
        return cost > ot.cost;
    }
};

void input() {
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

int dir[3][4][2] = {
        {{1, 0}, {-1, 0}},  // 3K + 1 번째 이동
        {{0, 1}, {0,  -1}},  // 3K + 2 번째 이동
        {{1, 0}, {0,  1}, {-1, 0}, {0, -1}}  // 3K 번째 이동
};

void pro() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < 3; k++)
                dist[i][j][k] = INF;

    dist[sx][sy][0] = 0;
    priority_queue<Elem> pq;
    pq.push(Elem(sx, sy, 0, 0));

    while (!pq.empty()) {
        Elem elem = pq.top();
        pq.pop();
        auto& [x, y, move, cost] = elem;
        if (dist[x][y][move] != cost) continue;
        int choice = move == 2 ? 4 : 2;
        for (int k = 0; k < choice; k++) {
            int nx = x + dir[move][k][0];
            int ny = y + dir[move][k][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (a[nx][ny] == -1) continue;

            int nmove = (move + 1) % 3;
            int ncost = cost + a[nx][ny];
            if (dist[nx][ny][nmove] <= ncost) continue;
            dist[nx][ny][nmove] = ncost;
            pq.push(Elem(nx, ny, nmove, ncost));
        }
    }

    int ans = INF;
    for (int move = 0; move < 3; move++) {
        ans = min(ans, dist[ex][ey][move]);
    }
    if (ans == INF) ans = -1;
    cout << ans;
}
int main() {
    input();
    pro();
    return 0;
}