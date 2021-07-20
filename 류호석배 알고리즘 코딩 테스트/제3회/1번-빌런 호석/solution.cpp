#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;
#define NM 100005
int N, K, P, X;
int num_flag[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}
};

void input(){
    cin >> N >> K >> P >> X;
}
int diff_one(int x,int y) {
    int res = 0;
    for (int i = 0; i < 7; i++) res += num_flag[x][i] != num_flag[y][i];
    return res;
}
int diff(int x,int y) {
    int res = 0;
    for (int rep = 1; rep <= K; rep++) {
        res += diff_one(x % 10, y % 10);
        x /= 10;
        y /= 10;
    }
    return res;
}
void pro() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        if (diff(i, X) <= P) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    pro();
    return 0;
}