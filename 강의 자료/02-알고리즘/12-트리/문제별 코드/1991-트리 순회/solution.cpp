#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 55

#include <vector>
int n;
int childs[NM][2];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> x;
		int X = x - 'A';
		for (int k = 0; k < 2; k++) {
			char ch;
			cin >> ch;
			if (ch == '.') childs[X][k] = -1;
			else childs[X][k] = ch - 'A';
		}
	}
}

void in_order(int x) {
	if (x == -1) return;
	in_order(childs[x][0]);
	cout << (char)(x + 'A');
	in_order(childs[x][1]);
}

void pre_order(int x) {
	if (x == -1) return;
	cout << (char)(x + 'A');
	pre_order(childs[x][0]);
	pre_order(childs[x][1]);
}

void post_order(int x) {
	if (x == -1) return;
	post_order(childs[x][0]);
	post_order(childs[x][1]);
	cout << (char)(x + 'A');
}

void pro() {
	pre_order(0);
	cout << '\n';
	in_order(0);
	cout << '\n';
	post_order(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}