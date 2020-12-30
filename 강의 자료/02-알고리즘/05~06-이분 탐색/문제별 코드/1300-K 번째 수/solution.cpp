#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

int N, K;

void input() {
	cin >> N >> K;
}

bool determination(ll candidate){
	ll sum = 0;
	for (int i = 1; i <= N; i++){
		sum += min((ll)N, candidate / i);
	}
	return sum >= K;
}

void pro() {
	ll L = 1, R = (ll)N * N, ans = 0;
	while (L <= R){
		ll mid = (L + R) / 2;
		if (determination(mid)){
			ans = mid;
			R = mid - 1;
		}else L = mid + 1;
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}