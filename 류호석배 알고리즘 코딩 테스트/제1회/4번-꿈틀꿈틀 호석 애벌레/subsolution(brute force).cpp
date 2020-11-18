#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define INF 0x7fffffff
#define NM 100005

using namespace std;

int n, K, D;
ll a[NM], ans;
void input() {
	cin >> n >> K;
	D = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void dfs(int x, ll energy) {
	if (x > n) {
		ans = max(ans, energy);
		return;
	}
	ll sum = 0;

	// x 번 먹이를 먹기로 결심!
	for (int i = x; i <= n; i++) {
		sum += a[i];
		if (sum >= K) {
			dfs(i + D + 1, energy + sum - K);
			break;
		}
	}

	// x 번 먹이를 안 먹기로 결심!
	dfs(x + 1, energy);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	dfs(1, 0);
	cout << ans;
	return 0;
}