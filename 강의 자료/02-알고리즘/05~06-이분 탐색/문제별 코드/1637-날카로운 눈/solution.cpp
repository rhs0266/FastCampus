#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 20005

int N, K;
int info[NM][3];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 0; j < 3; j++) cin >> info[i][j];
}

int counting(int A, int C, int B, int X) {
	if (X < A) return 0;
	if (C < X) return (C - A) / B + 1;
	return (X - A) / B + 1;
}

bool determination(ll candidate) {
	ll sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += counting(info[i][0], info[i][1], info[i][2], candidate);
	}
	return sum % 2 == 1;
}

void pro() {
	ll L = 1, R = 1ll << 31, ans = 0, ansCnt = 0;
	while (L <= R) {
		ll mid = (L + R) / 2;
		if (determination(mid)) {
			ans = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}
	if (ans == 0) {
		cout << "NOTHING";
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (info[i][0] <= ans && ans <= info[i][1] && (ans - info[i][0]) % info[i][2] == 0) {
				ansCnt++;
			}
		}
		cout << ans << " " << ansCnt;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}