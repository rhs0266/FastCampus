#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005
#define MOD 1000000009

int Dy[NM][4];

void preprocess() {
	// 초기값 구하기
	Dy[1][1] = 1;
	Dy[2][2] = 1;
	Dy[3][1] = Dy[3][2] = Dy[3][3] = 1;

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 4; i <= 100000; i++) {
		for (int cur = 1; cur <= 3; cur++) {
			for (int prev = 1; prev <= 3; prev++) {
				if (cur == prev) continue;
				Dy[i][cur] += Dy[i - cur][prev];
				Dy[i][cur] %= MOD;
			}
		}
	}
}

void pro() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int ans = 0;
		for (int cur = 1; cur <= 3; cur++) {
			ans += Dy[n][cur];
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	preprocess();
	pro();
	return 0;
}