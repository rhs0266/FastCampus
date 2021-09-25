#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 505

int n, a[NM], sum[NM][NM], dy[NM][NM];
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void preprocess() {
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			sum[i][j] = sum[i][j - 1] + a[j];
}
void pro() {
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			dy[i][j] = 0x7fffffff;
			for (int k = i; k < j; k++)
				dy[i][j] = min(dy[i][j], dy[i][k] + dy[k + 1][j] + sum[i][j]);
		}
	}
	cout << dy[1][n] << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int TT;
	cin >> TT;
	while (TT--) {
		input();
		preprocess();
		pro();
	}
	return 0;
}