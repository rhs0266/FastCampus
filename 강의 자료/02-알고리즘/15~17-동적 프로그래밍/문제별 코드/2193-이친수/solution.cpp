#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 95

int Q;
long long int dy[NM][2];

void input() {
	cin >> Q;
}

void pro() {
	// dy[i][j] = i자리 이친수 중에서 마지막 숫자가 j 인 경우의 수
	
	dy[1][0] = 0;
	dy[1][1] = 1;

	for (int i = 2; i <= Q; i++) {
		dy[i][0] = dy[i - 1][0] + dy[i - 1][1];
		dy[i][1] = dy[i - 1][0];
	}
	cout << dy[Q][0] + dy[Q][1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}