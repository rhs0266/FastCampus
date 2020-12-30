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

int bin_search(int A[],int L, int R, int X){
	while (L <= R){
		int mid = (L+R)/2;
		if (A[mid] == X)
			return true;

		if (A[mid] < X)
			L = mid + 1;
		else
			R = mid - 1;
	}
	return false;
}

void pro() {
	sort(A+1, A+1+N);
	int M;
	cin >> M;
	for (int i=1;i<=M;i++){
		int X;
		cin >> X;
		if (bin_search(A, 1, N, X)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}