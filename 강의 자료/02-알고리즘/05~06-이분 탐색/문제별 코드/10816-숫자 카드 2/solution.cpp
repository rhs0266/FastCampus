#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 500005

int N;
int A[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

int lower_bound(int A[], int L, int R, int X) {
	int ans = R + 1;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (A[mid] >= X) {
			ans = mid;
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}
	return ans;
}

int upper_bound(int A[], int L, int R, int X) {
	int ans = R + 1;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (A[mid] > X) {
			ans = mid;
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}
	return ans;
}

#include <vector>
void pro() {
	sort(A + 1, A + 1 + N);

	int M;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int X;
		cin >> X;
		cout << upper_bound(A, 1, N, X) - lower_bound(A, 1, N, X) << ' ';
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}