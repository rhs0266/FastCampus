#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005

int N;
int A[NM], Dy[NM];

void input(){
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	// 초기값 구하기
	Dy[0] = 0;

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 1; i <= N; i++) {
		for (int cnt = 1; cnt <= i; cnt++) {
			Dy[i] = max(Dy[i], Dy[i - cnt] + A[cnt]);
		}
	}

	// Dy배열로 정답 계산하기
	cout << Dy[N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}