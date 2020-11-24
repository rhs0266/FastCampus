#include <iostream>
typedef long long int ll;
using namespace std;

int N, S, nums[25], ans;
void input() {
	cin >> N >> S;
	for (int i=1;i<=N;i++)
		cin >> nums[i];
}

void rec_func(int k, int value) {
	if (k == N + 1) {
		if (value == S) ans++;
		return;
	}
	rec_func(k + 1, value + nums[k]);
	rec_func(k + 1, value);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	rec_func(1, 0);
	if (S == 0) ans--;
	cout << ans;
	return 0;
}