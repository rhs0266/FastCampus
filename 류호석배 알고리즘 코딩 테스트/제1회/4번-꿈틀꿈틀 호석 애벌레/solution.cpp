#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define INF 0x7fffffff
#define NM 100005

using namespace std;

int n, K;
ll a[NM], dy[NM];
void input() {
	cin >> n >> K;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void pro() {
    int right = 1;
    ll sum = 0, dyLeftMax = 0;

    for (int left = 1;left<=n;left++){
        dyLeftMax = max(dyLeftMax, dy[left-1]);

        while (right <= n && sum < K){
            sum += a[right++];
        }

        if (sum >= K){
            dy[right - 1] = max(dy[right - 1], dyLeftMax + (sum - K));
        }
        else break;
        sum -= a[left];
    }
	ll ans = 0;
	for (int i = 1; i <= n + 1; i++) ans = max(ans, dy[i]);
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}
