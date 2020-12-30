#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

int N, M;
int A[NM];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

bool determination(int len) {
	int cnt = 1, sum = 0;
	for (int i = 1; i <= N; i++) {
		if (sum + A[i] > len) {
			cnt++;
			sum = A[i];
		} else {
			sum += A[i];
		}
	}
	return cnt <= M;
}

void pro() {
	int L = A[1], R = 1000000000, ans = 0;
	for (int i=1;i<=N;i++) L = max(L, A[i]);
	while (L <= R) {
		ll mid = (L + R) / 2;
		if (determination(mid)) {
			ans = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}