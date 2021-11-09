#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 105
#define MOD 1000000000

int N;
int Dy[NM][10][10][10];

void input(){
	cin >> N;
}

void pro() {
	// 초기값 구하기
	for (int num = 1; num <= 9; num++) {
		Dy[1][num][num][num] = 1;
	}

	// 점화식을 토대로 Dy 배열 채우기
	for (int len = 2; len <= N; len++) {
		for (int prev = 0; prev <= 9; prev++) {
			for (int low = 0; low <= 9; low++) {
				for (int high = 0; high <= 9; high++) {
					for (int cur: {prev - 1, prev + 1}) {
						if (cur < 0 || cur > 9) continue;
						Dy[len][cur][min(low, cur)][max(high, cur)] += Dy[len - 1][prev][low][high];
						Dy[len][cur][min(low, cur)][max(high, cur)] %= MOD;
					}
				}
			}
		}
	}

	// Dy배열로 정답 계산하기
	int ans = 0;
	for (int num = 0; num <= 9; num++) {
		ans += Dy[N][num][0][9];
		ans %= MOD;
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