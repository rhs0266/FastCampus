#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

#include <vector>
int n, C;
struct Stone {
    int x, y, v;
};

vector<Stone> X[NM], Y[NM];

void input() {
    cin >> n >> C;
    for (int i = 1; i <= n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        X[x].push_back({ x, y, v });
        Y[y].push_back({ x, y, v });
    }
}

int W = -1, H = 100000, cnt = 0;
long long int V = 0, ans = 0;

void del(int y, int x) {
    for (auto& stone : Y[y]) {
        if (stone.x <= x) {
            cnt--;
            V -= stone.v;
        }
    }
}

void add(int x, int y) {
    for (auto& stone : X[x]) {
        if (stone.y <= y) {
            cnt++;
            V += stone.v;
        }
    }
}

void pro() {
    ans = V;
    while (W <= 100000 && H >= 0) {
        if (cnt > C) {
            del(H--, W);
        }
        else {
            add(++W, H);
        }
        if (cnt <= C) ans = max(ans, V);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    pro();
    return 0;
}