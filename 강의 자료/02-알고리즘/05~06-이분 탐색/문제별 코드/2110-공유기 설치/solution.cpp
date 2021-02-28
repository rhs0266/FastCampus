#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 200005

int N, C;
int A[NM];

void input() {
	cin >> N >> C;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

bool determination(int D) {
	int cnt = 1, last = A[1];
	for (int i=2;i<=N;i++){
		if (A[i] - last < D) continue;
		last = A[i];
		cnt++;
	}
	return cnt >= C;
}

void pro() {
	sort(A+1,A+1+N);
	int L = 1, R = 1000000000, ans = 0;
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