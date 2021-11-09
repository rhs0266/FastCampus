#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005

int Q;
long long int Dy[65][10];

void input() {
	cin >> Q;
}

void preprocess() {
	// 초기값 구하기
	for (int num = 0; num <= 9; num++) {
		Dy[1][num] = 1;
	}

	// 점화식을 토대로 Dy 배열 채우기
	for (int len = 2; len <= 64; len++) {
		for (int num = 0; num <= 9; num++) {
			// 길이가 len이고 num으로 끝나는 개수를 계산하자 == Dy[len][num] 을 계산하자.
			for (int prev = 0; prev <= num; prev++) {
				Dy[len][num] += Dy[len - 1][prev];
			}
		}
	}
}

void pro() {
	for (int rep = 1; rep <= Q; rep++) {
		int N; cin >> N;
		long long int ans = 0;
		for (int num = 0; num <= 9; num++) ans += Dy[N][num];
		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	preprocess();
	input();
	pro();
	return 0;
}