#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005

int Q, MOD = 1000000009;
int dy[NM];

void input() {
	cin >> Q;
}

void preprocess() {
	// dy[i] := i 를 1, 2, 3의 합으로 표현하는 방법
	// dy[0] 은 사실 문제 정의 상 말이 안되지만, 이후 점화식을 간단하게 적용하기 위해서
	// "아무것도 안 더한다"는 것을 하나의 경우로 생각해줘서 1을 적어준다.
	// 이를 통해서 dy[1, 2, 3]에 대해서도 일관성있는 점화식을 작성할 수 있기 때문이다.
	// 이게 불편하다면 dy[1, 2, 3] 에 대해 모두 값을 적어주고 시작해도 상관없다.
	dy[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		dy[i] = dy[i - 1];  // 마지막에 1을 더하는 경우의 수
		if (i - 2 >= 0) dy[i] += dy[i - 2];  // 마지막에 2을 더하는 경우의 수
		dy[i] %= MOD;
		if (i - 3 >= 0) dy[i] += dy[i - 3];  // 마지막에 3을 더하는 경우의 수
		dy[i] %= MOD;
	}
}

void pro() {
	preprocess();
	while (Q-- > 0) {
		int x;
		cin >> x;
		int res = 0;
		// 홀수 개를 더한 경우
		for (int mid = 1; mid <= 3; mid++)  // 가운데에 mid 를 더한 상황
			if (x - mid >= 0 && (x - mid) % 2 == 0) {  // 양쪽이 대칭을 이루게 더하기 위함
				res += dy[(x - mid) / 2];
				res %= MOD;
			}

		// 짝수 개를 더한 경우 (사실상 위에서 mid 가 0 인 경우. 즉, for loop을 0 부터 시작해도 됨)
		if (x % 2 == 0) {  // 양쪽이 대칭을 이루게 더하기 위함
			res += dy[x / 2];
			res %= MOD;
		}
		cout << res << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}