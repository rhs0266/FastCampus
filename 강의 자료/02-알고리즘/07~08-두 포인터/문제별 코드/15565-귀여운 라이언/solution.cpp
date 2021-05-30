#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 1000005

int N, K, A[NM];

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	int right = 0, ans = -1, sum = 0;
	for (int left = 1; left <= N; left++) {
		while (right < N && sum < K) {
			right++;
			if (A[right] == 1) sum++;
		}

		if (sum == K) {
			if (ans == -1) ans = right - left + 1;
			ans = min(ans, right - left + 1);
		}

		if (A[left] == 1) sum--;
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}