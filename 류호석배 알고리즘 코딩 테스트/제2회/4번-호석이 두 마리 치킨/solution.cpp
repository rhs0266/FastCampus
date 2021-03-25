#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 105

#include <vector>
int n, m;
vector<int> con[NM];
int dist[NM][NM];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        con[x].push_back(y);
        con[y].push_back(x);
    }
}

#include <queue>
void bfs(int S, int dist[]) {
    for (int i = 1; i <= n; i++) { dist[i] = -1; }
    queue<int> Q;
    Q.push(S);
    dist[S] = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int y : con[x]) {
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                Q.push(y);
            }
        }
    }
}

void pro() {
    for (int i = 1; i <= n; i++) bfs(i, dist[i]);

    int ans = 0x7fffffff, ans_x = 0, ans_y = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = 0;
            for (int k = 1; k <= n; k++) {
                sum += min(dist[i][k], dist[j][k]) * 2;
            }
            if (ans > sum) {
                ans = sum;
                ans_x = i;
                ans_y = j;
            }
        }
    }
    cout << ans_x << " " << ans_y << " " << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    pro();
    return 0;
}