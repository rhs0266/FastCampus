#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005

int N;
int A[NM], Dy[NM][10];

void input(){
	cin >> N;
}

void pro() {
	// 초기값 구하기
	for (int num = 0; num <= 9; num++) {
		Dy[1][num] = 1;
	}

	// 점화식을 토대로 Dy 배열 채우기
	for (int len = 2; len <= N; len++) {
		for (int num = 0; num <= 9; num++) {
			// 길이가 len이고 num으로 끝나는 개수를 계산하자 == Dy[len][num] 을 계산하자.
			for (int prev = 0; prev <= num; prev++) {
				Dy[len][num] += Dy[len - 1][prev];
				Dy[len][num] %= 10007;
			}
		}
	}

	// Dy배열로 정답 계산하기
	int ans = 0;
	for (int num = 0; num <= 9; num++) {
		ans += Dy[N][num];
		ans %= 10007;
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}