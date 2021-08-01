#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 32005

int n, m, indeg[NM];
vector<int> con[NM];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		indeg[y]++;
	}
}

#include <queue>
void pro() {
	queue<int> Q;

	// 제일 앞에 "정렬될 수 있는" 정점 찾기
	for (int i = 1; i <= n; i++) if (indeg[i] == 0) Q.push(i);

	// 정렬될 수 있는 정점이 있다면?
	// 1. 정렬 결과에 추가하기
	// 2. 정점과 연결된 간선 제거하기
	// 3. 새롭게 "정렬될 수 있는" 정점 Queue에 추가하기
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		cout << x << " ";
		for (int y : con[x]) {
			indeg[y]--;
			if (indeg[y] == 0) Q.push(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}