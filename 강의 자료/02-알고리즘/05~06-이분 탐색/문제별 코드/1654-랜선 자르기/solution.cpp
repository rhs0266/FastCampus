#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 10005

int N, K;
int A[NM];

void input() {
	cin >> K >> N;
	for (int i = 1; i <= K; i++) cin >> A[i];
}

bool determination(ll len) {
	ll sum = 0;
	for (int i = 1; i <= K; i++) {
		sum += A[i] / len;
	}
	return sum >= N;
}

void pro() {
	ll L = 1, R = 1ll << 31, ans = 0, ansCnt = 0;
	while (L <= R) {
		ll mid = (L + R) / 2;
		if (determination(mid)) {
			ans = mid;
			L = mid + 1;
		}
		else R = mid - 1;
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}