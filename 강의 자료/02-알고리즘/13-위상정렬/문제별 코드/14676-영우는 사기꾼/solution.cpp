#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 100005

int K, n, m, indeg[NM], cnt[NM], satisfaction[NM];
vector<int> con[NM];

void input() {
	cin >> n >> m >> K;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		indeg[y]++;
	}
}

void pro() {
	bool abnormal = false;
	while (K--) {
		int t, x;
		cin >> t >> x;
		if (t == 1){
			// x 의 선행 건물들이 모두 지어졌는 지 확인하기
			if (satisfaction[x] < indeg[x])
				abnormal = true;
			
			cnt[x]++;
			// x 가 처음 지어진 것이라면 x가 영향을 주는 건물들에 "너희의 선행 건물 중 하나가 처음 지어졌어" 라고 알려주기
			if (cnt[x] == 1)
				for (int y: con[x])
					satisfaction[y]++;
		}
		else{
			// x 라는 건물이 한 개 이상 지어져 있는 지 확인하기
			if (cnt[x] == 0)
				abnormal = true;
			
			cnt[x]--;
			// x 가 더 이상 남아있지 않다면, "너희의 선행 건물 중 하나가 사라졌어" 라고 알려주기
			if (cnt[x] == 0)
				for (int y: con[x])
					satisfaction[y]--;
		}
	}
	if (abnormal) cout << "Lier!";
	else cout << "King-God-Emperor";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}