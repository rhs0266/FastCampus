#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 500005

int N, M;
int A[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

int lower_bound(int A[], int L, int R, int X) {
	int res = R + 1;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (A[mid] >= X) {
			res = mid;
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}
	return res;
}

#include <vector>
void pro() {
	sort(A + 1, A + 1 + N);

	int best_sum = 0x7fffffff;
	int v1 = 0, v2 = 0;
	for (int left = 1; left <= N - 1; left++) {
		// A[left] 용액을 쓸 것이다. 고로 -A[left] 와 가장 가까운 용액을 자신의 오른쪽 구간에서 찾자.
		int candidate = lower_bound(A, left + 1, N, -A[left]);

		// A[candidate - 1] 와 A[candidate] 중에 A[left] 와 섞었을 때의 정보를 정답에 갱신시킨다.

		// 1. A[left] + A[candidate - 1]
		if (left < candidate - 1 && abs(A[left] + A[candidate - 1]) < best_sum) {
			best_sum = abs(A[left] + A[candidate - 1]);
			v1 = A[left];
			v2 = A[candidate - 1];
		}

		// 2. A[left] + A[candidate]
		if (candidate <= N && abs(A[left] + A[candidate]) < best_sum) {
			best_sum = abs(A[left] + A[candidate]);
			v1 = A[left];
			v2 = A[candidate];
		}
	}
	cout << v1 << " " << v2;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}