#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

int N, M;
int A[NM];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	sort(A + 1, A + 1 + N);

	int R = 1, ans = 0x7fffffff;
	for (int L = 1; L <= N; L++) {
		while (R + 1 <= N && A[R] - A[L] < M) ++R;
		if (A[R] - A[L] >= M) ans = min(ans , A[R] - A[L]);
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}