#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 20005

int N;
string a[NM];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
}

void pro() {
	sort(a + 1, a + 1 + N, [](const string& A, const string& B) {
		if (A.length() != B.length()) return A.length() < B.length();
		return A < B;
	});
	for (int i = 1; i <= N; i++) {
		if (a[i] == a[i - 1]) continue;
		cout << a[i] << '\n';
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}