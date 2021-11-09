#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005
#define MOD 9901

int N;
int A[NM][2], Dy[NM][3];

void input() {
	cin >> N;
}

void pro() {
	// 초기값 구하기
	Dy[1][0] = 1;
	Dy[1][1] = 1;
	Dy[1][2] = 1;

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 2; i <= N; i++) {
		for (int prev = 0; prev <= 2; prev++) {
			Dy[i][0] += Dy[i - 1][prev];
			Dy[i][0] %= MOD;
			for (int j = 0; j <= 1; j++) {
				if (prev & (1 << j)) continue;
				Dy[i][1 << j] += Dy[i - 1][prev];
				Dy[i][1 << j] %= MOD;
			}
		}
	}

	cout << (Dy[N][0] + Dy[N][1] + Dy[N][2]) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}