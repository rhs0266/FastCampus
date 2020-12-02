#include <iostream>
#include <string>
#include <algorithm>
typedef long long int ll;
using namespace std;

int N;
string a[50005];
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		a[i] = a[i].substr(a[i].find(".") + 1);
	}
}

void pro() {
	sort(a + 1, a + 1 + N);
	for (int i = 1; i <= N;) {
		int j = i + 1, cnt = 1;
		for (; j <= N; j++) {
			if (a[i] == a[j]) cnt++;
			else break;
		}
		cout << a[i] << " " << cnt << "\n";
		i = j;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}