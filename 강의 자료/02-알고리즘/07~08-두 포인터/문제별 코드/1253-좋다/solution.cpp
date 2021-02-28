#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 2005

int N;
int A[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

bool func(int target_idx) {
	int L = 1, R = N;
	int target = A[target_idx];
	while (L < R) {
		if (L == target_idx) L++;
		else if (R == target_idx) R--;
		else {
			if (A[L] + A[R] > target) R--;
			else if (A[L] + A[R] == target) return true;
			else L++;
		}
	}
	return false;
}

void pro() {
	sort(A + 1, A + 1 + N);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (func(i)) ans++;
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}