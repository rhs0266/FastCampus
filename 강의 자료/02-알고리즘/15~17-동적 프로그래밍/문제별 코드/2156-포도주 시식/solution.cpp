#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 10005

int N;
int A[NM], Dy[NM][2];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	// 초기값 구하기
	Dy[1][0] = A[1];
	Dy[1][1] = A[1];

	if (N >= 2) {
		Dy[2][0] = A[2];
		Dy[2][1] = A[1] + A[2];
	}

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 3; i <= N; i++) {
		Dy[i][0] = max(Dy[i - 2][0] + A[i], Dy[i - 2][1] + A[i]);
		Dy[i][0] = max(Dy[i][0], max(Dy[i - 3][0], Dy[i - 3][1]) + A[i]);
		Dy[i][1] = Dy[i - 1][0] + A[i];
	}

	cout << max({ Dy[N][0], Dy[N][1], Dy[N - 1][0], Dy[N - 1][1] });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}