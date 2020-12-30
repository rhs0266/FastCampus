#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 1000005

int N, M;
int A[NM];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

bool determination(int H) {
	ll sum = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] > H) sum += A[i] - H;
	}
	return sum >= M;
}

void pro() {
	ll L = 0, R = 2000000000, ans = 0;
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