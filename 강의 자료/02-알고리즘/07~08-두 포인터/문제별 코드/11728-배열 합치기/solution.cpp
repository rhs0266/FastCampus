#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 1000005

int N, M;
int A[NM], B[NM];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
}

void pro() {
	int L = 1, R = 1;
	while (L <= N && R <= M){
		if (A[L] <= B[R]) cout << A[L++] << " ";
		else cout << B[R++] << " ";
	}
	while (L <= N) cout << A[L++] << " ";
	while (R <= M) cout << B[R++] << " ";
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}