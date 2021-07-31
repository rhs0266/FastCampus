#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005

int n, K, a[NM], par[NM];

void input() {
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

#include <queue>
void pro() {
	// 각 노드의 부모 노드 인덱스를 계산하자. 루트 노드가 1번 노드임을 주의하라.
	// 편의상 0번 정점의 부모를 -1 로 하자.
	par[0] = -1;
	par[1] = 0;

	// last := 이번에 자식 정점들을 찾을 노드의 인덱스
	int last = 1;
	for (int i = 2; i <= n; i++, last++) {
		for (; i <= n; i++) { // i번부터 연속한 수를 가진 정점을 모두 last 의 자식으로 묶는다.
			par[i] = last;
			if (i < n && a[i] + 1 != a[i + 1]) {
				break;
			}
		}
	}

	int kIdx = 0;  // 수가 K인 정점의 인덱스
	for (int i = 1; i <= n; i++) if (a[i] == K) kIdx = i;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		// 사촌 := 부모의 부모는 동일하나 부모는 다른 정점의 개수
		if (par[par[i]] == par[par[kIdx]] && par[i] != par[kIdx])
			ans++;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (;;) {
		input();
		if (n == 0 && K == 0) break;
		pro();
	}
	return 0;
}