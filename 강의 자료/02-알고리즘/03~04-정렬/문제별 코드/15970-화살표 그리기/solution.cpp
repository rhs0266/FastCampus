#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;

#define NM 5005

int N;
vector<int> a[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int coord, color;
		cin >> coord >> color;
		a[color].push_back(coord);
	}
}

int toLeft(int color, int x) {
	if (x == 0) return 0x7fffffff;
	return a[color][x] - a[color][x - 1];
}

int toRight(int color, int x) {
	if (x + 1 == a[color].size()) return 0x7fffffff;
	return a[color][x + 1] - a[color][x];
}

void pro() {
	int ans = 0;
	for (int color = 1; color <= N; color++) {
		sort(a[color].begin(), a[color].end());
		for (int i = 0; i < a[color].size(); i++) {
			int left = toLeft(color, i);
			int right = toRight(color, i);
			ans += min(left, right);
		}
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}