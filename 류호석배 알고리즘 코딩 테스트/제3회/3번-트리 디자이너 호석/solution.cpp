#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
#define NM 100005
#define INF 0x7fffffff
#define MOD 1000000007

int n, a[NM], dy[NM][10];
vector<int> con[NM];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n-1;i++){
        int x, y;
        cin >> x >> y;
        con[x].push_back(y);
        con[y].push_back(x);
    }
}

void dfs(int x, int prev){
    dy[x][a[x]] = 1;
    for (int y: con[x]){
        if (y == prev) continue;
        dfs(y, x);
        for (int num=0;num<=9;num++){
            dy[x][num] += dy[y][num];
            dy[x][num] %= MOD;
        }
        for (int num=a[x];num<=9;num++){
            dy[x][a[x]] += dy[y][num];
            dy[x][a[x]] %= MOD;
        }
    }
}

void pro() {
    dfs(1, -1);
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dy[1][i];
        ans %= MOD;
    }
    cout << ans;
}
int main() {
    input();
    pro();
    return 0;
}