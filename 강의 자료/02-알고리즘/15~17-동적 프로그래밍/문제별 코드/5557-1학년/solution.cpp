#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 105

int N;
int A[NM];
long long int Dy[NM][21];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	// 초기값 구하기
	Dy[1][A[1]] = 1;

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 2; i <= N - 1; i++) {
		for (int prev = 0; prev <= 20; prev++) {
			for (int cur : {prev - A[i], prev + A[i]}) {
				if (cur < 0 || cur > 20) continue;
				Dy[i][cur] += Dy[i - 1][prev];
			}
		}
	}

	// Dy배열로 정답 계산하기
	cout << Dy[N - 1][A[N]];
 }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}