#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 25

int Q;
int dy[NM];

void input() {
	cin >> Q;
}

void pro() {
	dy[0] = 0;
	dy[1] = 1;
	for (int i = 2; i <= Q; i++)
		dy[i] = dy[i - 1] + dy[i - 2];
	cout << dy[Q];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}