#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 45

int Q;
long long int dy[NM][2];

void input() {
	cin >> Q;
}

// dy[][] 를 미리 계산해 놓기
void preprocess() {
	// dy[i][k] := fibonacci(i) 를 호출했을 때, k 가 출력되는 횟수
	dy[0][0] = 1;
	dy[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		dy[i][0] = dy[i - 1][0] + dy[i - 2][0];
		dy[i][1] = dy[i - 1][1] + dy[i - 2][1];
	}
}

void pro() {
	while (Q--) {
		int x; cin >> x;
		cout << dy[x][0] << " " << dy[x][1] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	preprocess();
	pro();
	return 0;
}