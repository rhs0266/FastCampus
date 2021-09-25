#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 5005

#include <string>
string str;
int N, MOD = 1000000, Dy[NM];

void input(){
	cin >> str;
	N = str.size();
}

bool check(char A, char B) {  // 'AB' 라는 두 자리 숫자가 하나의 수로 해독이 가능한가?
	if (A == '0') return false;
	if (A == '1') return true;
	if (A >= '3') return false;
	return B <= '6';
}

void pro() {

	// 초기값 구하기
	if (str[0] != '0') Dy[0] = 1;

	// 점화식을 토대로 Dy 배열 채우기
	for (int i = 1; i < N; i++) {
		// i 번 숫자를 단독으로 해석 가능할 때
		if (str[i] != '0') Dy[i] = Dy[i - 1];

		// i - 1번과 i 번 숫자를 하나의 문자로 해석 가능할 때
		if (check(str[i - 1], str[i])) {
			if (i >= 2) Dy[i] += Dy[i - 2];
			else Dy[i] += 1;
			Dy[i] %= MOD;
		}
	}

	// Dy배열로 정답 계산하기
	cout << Dy[N - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}