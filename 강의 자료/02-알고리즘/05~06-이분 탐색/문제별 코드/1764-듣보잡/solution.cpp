#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 500005

int N, M;
string A[NM], B[NM];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
}

int bin_search(string A[], int L, int R, string X) {
	while (L <= R) {
		int mid = (L + R) / 2;
		if (A[mid] == X)
			return true;

		if (A[mid] < X)
			L = mid + 1;
		else
			R = mid - 1;
	}
	return false;
}

#include <vector>
void pro() {
	sort(A + 1, A + 1 + N);
	sort(B + 1, B + 1 + M);
	vector<string> ans;
	for (int i = 1; i <= M; i++) {
		if (bin_search(A, 1, N, B[i])) ans.push_back(B[i]);
	}
	cout << ans.size() << '\n';
	for (string x : ans) cout << x << '\n';
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}