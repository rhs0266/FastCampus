#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 15

int Dy[NM];

void preprocess() {
	// 초기값 구하기
	Dy[1] = 1;
	Dy[2] = 2;
	Dy[3] = 4;
	
	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 4; i <= 11; i++) {
		Dy[i] = Dy[i - 1] + Dy[i - 2] + Dy[i - 3];
	}
}

void pro() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		cout << Dy[n] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	preprocess();
	pro();
	return 0;
}