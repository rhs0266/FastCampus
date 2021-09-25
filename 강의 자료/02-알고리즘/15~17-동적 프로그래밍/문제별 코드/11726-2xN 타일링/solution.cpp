#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005

int n;
int Dy[NM];

void input(){
	cin >> n;
}

void pro() {
	Dy[1] = 1;
	Dy[2] = 2;

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 3; i <= n; i++){
		Dy[i] = (Dy[i - 1] + Dy[i - 2]) % 10007;
	}

	cout << Dy[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}