#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 500005

int N, S;
int A[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> S;
}

void pro() {
	sort(A + 1, A + 1 + N);
	int ans = 0;
	for (int L = 1, R = N; L < R;){
		if (A[L] + A[R] == S) ans++;
		if (A[L] + A[R] >= S) R--;
		else L++;
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}