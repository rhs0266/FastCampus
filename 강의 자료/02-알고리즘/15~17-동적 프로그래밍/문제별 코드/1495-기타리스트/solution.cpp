#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 55

int N, S, M;
int A[NM];
bool Dy[NM][1001];

void input() {
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	// 초기값 구하기
	Dy[0][S] = true;

	// 점화식을 토대로 Dy 배열 채우기
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		bool flag = false;
		ans = 0;
		for (int prev = 0; prev <= M; prev++) {
			if (!Dy[i - 1][prev]) continue;
			for (int cur : {prev - A[i], prev + A[i]}) {
				if (cur < 0 || cur > M) continue;
				ans = max(ans, cur);
				Dy[i][cur] = true;
				flag = true;
			}
		}
		if (!flag) {
			cout << -1;
			return;
		}
	}

	// Dy배열로 정답 계산하기
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}