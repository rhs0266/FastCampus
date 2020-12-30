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
	for (int i = 1; i <= M; i++) cin >> A[i];
}

bool determination(int height) {
	int last = 0;  // 밝혀진 마지막 위치
	for (int i = 1; i <= M; i++) {
		if (A[i] - last <= height) {
			last = A[i] + height;
		} else {
			return false;
		}
	}
	return last >= N;
}

void pro() {
	int L = 0, R = N, ans = N;
	sort(A + 1, A + M + 1);
	while (L <= R) {
		int mid = (L + R) / 2;
		if (determination(mid)) {
			ans = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}