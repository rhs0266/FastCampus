#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005

int N;
int A[NM][2], Dy[NM][3];

void input() {
	cin >> N;
	for (int j = 0; j <= 1; j++)
		for (int i = 1; i <= N; i++)
			cin >> A[i][j];
}

void pro() {
	for (int i = 1; i <= N; i++) for (int j = 0; j < 3; j++) Dy[i][j] = 0;

	// 초기값 구하기
	Dy[1][1] = A[1][0];
	Dy[1][2] = A[1][1];

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 2; i <= N; i++) {
		for (int prev = 0; prev <= 2; prev++) {
			Dy[i][0] = max(Dy[i][0], Dy[i - 1][prev]);
			for (int j = 0; j <= 1; j++) {
				if (prev & (1 << j)) continue;
				Dy[i][1 << j] = max(Dy[i][1 << j], Dy[i - 1][prev] + A[i][j]);
			}
		}
	}

	cout << max({ Dy[N][0], Dy[N][1], Dy[N][2] });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int TT; cin >> TT;
	while (TT--) {
		input();
		pro();
	}
	return 0;
}