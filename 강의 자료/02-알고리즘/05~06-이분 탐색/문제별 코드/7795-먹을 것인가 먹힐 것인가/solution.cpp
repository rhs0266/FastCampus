#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 20005

int N, M;
int A[NM], B[NM];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
}

int lower_bound(int A[], int L, int R, int X) {
	int res = L - 1;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (A[mid] < X) {
			res = mid;
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	return res;
}

#include <vector>
void pro() {
	sort(B + 1, B + 1 + M);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		// A[i] 를 선택했을 때, B 에서는 A[i]보다 작은 게 몇 개나 있는 지 count하기
		ans += lower_bound(B, 1, M, A[i]);
	}
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int TT;
	cin >> TT;
	while (TT--) {
		input();
		pro();
	}
	return 0;
}