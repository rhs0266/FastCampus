#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005

int N;
int A[4], dy_min[2][4], dy_max[2][4];

void input() {
	cin >> N;
}

int Max(int x, int y) { return x > y ? x : y; }
int Min(int x, int y) { return x < y ? x : y; }
void pro() {
	// 초기값 구하기
	for (int j = 1; j <= 3; j++) cin >> dy_min[1][j], dy_max[1][j] = dy_min[1][j];

	// 점화식을 통해 dy 배열 계산하기
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) cin >> A[j]; 
		for (int cur = 1; cur <= 3; cur++) {
			dy_max[i % 2][cur] = 0;
			dy_min[i % 2][cur] = 1e8;
			for (int prev = 1; prev <= 3; prev++) {
				if (abs(cur - prev) > 1) continue;
				dy_max[i % 2][cur] = max(dy_max[i % 2][cur], dy_max[(i + 1) % 2][prev] + A[cur]);
				dy_min[i % 2][cur] = min(dy_min[i % 2][cur], dy_min[(i + 1) % 2][prev] + A[cur]);
			}
		}
	}

	cout << max(max(dy_max[N % 2][1], dy_max[N % 2][2]), dy_max[N % 2][3]) << " ";
	cout << min(min(dy_min[N % 2][1], dy_min[N % 2][2]), dy_min[N % 2][3]) << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}