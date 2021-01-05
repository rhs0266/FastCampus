#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

int N;
int A[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
}

void pro() {
	sort(A + 1, A + 1 + N);
	
	int best_sum = 0x7fffffff;
	int v1 = 0, v2 = 0, L = 1, R = N;

	while (L < R){  // L == R 인 상황이면 용액이 한 개 뿐인 것이므로, L < R 일 때까지만 반복한다.
		if (best_sum > abs(A[L] + A[R])) {
			best_sum = abs(A[L] + A[R]);
			v1 = A[L];
			v2 = A[R];
		}
		if (A[L] + A[R] > 0) R--;
		else L++;
	}
	cout << v1 << " " << v2;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}