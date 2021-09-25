#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005

int N;
int A[3], Dy[NM][3];

void input(){
	cin >> N;
}

void pro() {
	// Dy[i][j] := 1 ~ i번 집까지 칠했고, i번 집을 j번 색으로 색칠하는 경우 중 최소 비용

	// 초기값 구하기
	Dy[0][0] = Dy[0][1] = Dy[0][2] = 0;

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) cin >> A[j];
		Dy[i][0] = min(Dy[i - 1][1], Dy[i - 1][2]) + A[0];
		Dy[i][1] = min(Dy[i - 1][0], Dy[i - 1][2]) + A[1];
		Dy[i][2] = min(Dy[i - 1][0], Dy[i - 1][1]) + A[2];
	}

	// Dy배열로 정답 계산하기
	cout << min(Dy[N][0], min(Dy[N][1], Dy[N][2]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}