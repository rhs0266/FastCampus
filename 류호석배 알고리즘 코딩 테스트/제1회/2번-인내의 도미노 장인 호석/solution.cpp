#include <iostream>
#include <algorithm>
#define NM 105
#define MOD 1000000007
const double EPS = 1e-10;
using namespace std;
typedef long long int ll;

#include <assert.h>
int n, m, R, ans;
int a[105][105], backup[105][105];

void input() {
    cin >> n >> m >> R;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j], backup[i][j] = a[i][j];
}

void attack(int x, int y, char dir) {
    if (a[x][y] == 0) return;
    int dx = 0, dy = 0;
    if (dir == 'E') dy = 1;
    else if (dir == 'W') dy = -1;
    else if (dir == 'S') dx = 1;
    else if (dir == 'N') dx = -1;
    else assert(false);
    int cnt = a[x][y];
    while (x >= 1 && x <= n && y >= 1 && y <= m && cnt >= 1) {
        if (a[x][y] != 0) ans++;
        cnt = max(cnt - 1, a[x][y] - 1);
        a[x][y] = 0;
        x += dx, y += dy;
    }
}

void pro() {
    for (int i = 1; i <= R; i++) {
        // attacker
        int X, Y;
        char dir;
        cin >> X >> Y >> dir;
        attack(X, Y, dir);

        // defender
        cin >> X >> Y;
        a[X][Y] = backup[X][Y];
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (a[i][j] == 0 ? "F" : "S") << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}