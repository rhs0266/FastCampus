#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;

#define NM 100005

int N;
ll a[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
}

void pro() {
    sort(a+1, a+1+N);
	ll mode = a[1];
    int modeCnt = 1, curCnt = 1;
	for (int i = 2; i <= N; i++) {
		if (a[i] == a[i - 1]) curCnt++;
		else curCnt = 1;
		if (modeCnt < curCnt) {
			modeCnt = curCnt;
			mode = a[i];
		}
	}
	cout << mode;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}