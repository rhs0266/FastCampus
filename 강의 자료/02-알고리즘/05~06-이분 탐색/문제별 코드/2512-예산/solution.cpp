#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 10005

int N, M;
int A[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> M;
}

bool determination(int limit) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += min(A[i], limit);
	}
	return sum <= M;
}

void pro() {
	int L = 0, R = 0, ans = 0;
	for (int i=1;i<=N;i++) R = max(R, A[i]);
	while (L <= R) {
		int mid = (L + R) / 2;
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