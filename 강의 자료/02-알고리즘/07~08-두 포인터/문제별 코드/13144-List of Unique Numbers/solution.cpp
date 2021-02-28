#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

int N;
int A[NM], cnt[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	long ans = 0;
	for (int L = 1, R = 0; L <= N; L++) {  // L 마다 R 을 최대한 옮겨 줄 계획이다.
		// R 을 옮길 수 있는 만큼 옮긴다.
		while (R + 1 <= N && cnt[A[R + 1]] == 0) {
			R++;
			cnt[A[R]]++;
		}

		// 정답을 갱신한다
		ans += R - L + 1;

		// L 을 옮겨주면서 A[L] 의 개수를 감소시킨다.
		cnt[A[L]]--;
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}