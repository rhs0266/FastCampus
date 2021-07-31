#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 10005

#include <vector>
int n;
int a[NM];

void input() {
	while (!cin.eof()) {
		cin >> a[++n];
	}
	n--;
}

// 현재 Subtree가 a[l...r] 일 때, 후위 순회를 하는 함수.
void traverse(int l, int r) {
	if (l > r) return;
	int mid = r;  // 왼쪽과 오른쪽 subtree를 가르는 기준 위치를 나타내는 변수
	for (int i = l + 1; i <= r; i++) {
		if (a[i] > a[l]) {
			mid = i - 1;
			break;
		}
	}
	
	// 후위 순회
	traverse(l + 1, mid);
	traverse(mid + 1, r);
	cout << a[l] << "\n";
}

void pro() {
	traverse(1, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}