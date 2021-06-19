#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define NM 55

#include <vector>
int n, root, erased, leaf[NM];
vector<int> child[NM];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int par;
		cin >> par;
		if (par == -1) {
			root = i;
		}
		else {
			child[par].push_back(i);
		}
	}
	cin >> erased;
}

void DFS(int x, int par) {
	if (child[x].empty())
		leaf[x]++;
	for (int y : child[x]) {
		if (y == par) continue;
		DFS(y, x);
		leaf[x] += leaf[y];
	}
}

void pro() {
	for (int i = 0; i < n; i++) {
		for (auto it = child[i].begin(); it != child[i].end(); it++){
			if (*it == erased) {
				child[i].erase(it);
				break;
			}
		}
	}

	if (root != erased) DFS(root, -1);

	cout << leaf[root];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}