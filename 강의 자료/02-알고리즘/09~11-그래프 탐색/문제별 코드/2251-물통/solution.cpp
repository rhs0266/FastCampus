#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 205

struct State {
	int X[3];
	State() {}
	State(int x, int y, int z) {
		X[0] = x, X[1] = y, X[2] = z;
	}
	State(int _X[]) {
		for (int i = 0; i < 3; i++) X[i] = _X[i];
	}
	State move(int from, int to, int Limit[]) {
		State res(X);
		if (X[from] + X[to] <= Limit[to]) {  // 만약 from 을 전부 부을 수 있다면
			res.X[to] = res.X[from] + res.X[to];
			res.X[from] = 0;
		}
		else {  // from 의 일부만 옮길 수 있는 경우
			res.X[from] -= Limit[to] - res.X[to];
			res.X[to] = Limit[to];
		}
		return res;
	}
};

int Limit[3];
void input() {
	cin >> Limit[0] >> Limit[1] >> Limit[2];
}

#include <queue>
queue<State> Q;
bool possible[NM];
bool visit[NM][NM][NM];

bool isVisited(State s) { return visit[s.X[0]][s.X[1]][s.X[2]]; }
void checkVisit(State s) { visit[s.X[0]][s.X[1]][s.X[2]] = true; }
void pro() {
	Q.push(State(0, 0, Limit[2]));
	checkVisit(State(0, 0, Limit[2]));
	while (!Q.empty()) {
		State cur = Q.front();
		Q.pop();
		if (cur.X[0] == 0) possible[cur.X[2]] = true;
		for (int from = 0; from < 3; from++) {
			for (int to = 0; to < 3; to++) {
				if (from == to) continue;
				State nxt = cur.move(from, to, Limit);
				if (isVisited(nxt)) continue;
				checkVisit(nxt);
				Q.push(nxt);
			}
		}
	}
	for (int i = 0; i <= 200; i++) if (possible[i]) cout << i << " ";
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}