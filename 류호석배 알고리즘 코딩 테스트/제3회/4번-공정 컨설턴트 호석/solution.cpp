#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
#define NM 100005
#define INF 0x7fffffff

int n, X, a[NM];

void input() {
    cin >> n >> X;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

bool check(int num) {
    vector<int> vec(num, 0);
    priority_queue<int, vector<int>, greater<int>> Q(vec.begin(), vec.end());
    for (int i = 1; i <= n; i++) {
        int pick = Q.top();
        Q.pop();
        if (pick + a[i] > X) return false;
        Q.push(pick + a[i]);
    }
    return true;
}

void pro() {
    int L = 1, R = n, ans = n;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    cout << ans;
}

int main() {
    input();
    pro();
    return 0;
}