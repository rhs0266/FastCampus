#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 500005

int N, K;
int A[NM];

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	int R = 0, sum = 0, ans = -100 * N;
	for (int L = 1; L + K - 1 <= N; L++) {
		// L - 1 을 구간에서 제외하기
		sum -= A[L - 1];

		// R 을 옮길 수 있을 때 까지 옮기기
		while (R + 1 <= L + K - 1)
			sum += A[++R];

		// [L ... R] 의 합, 즉 sum이 조건을 만족하면 정답 갱신하기
		ans = max(ans, sum);
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}