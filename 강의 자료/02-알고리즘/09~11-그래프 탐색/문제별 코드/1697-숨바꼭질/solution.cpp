#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

int N, K;

void input() {
	cin >> N >> K;
}

#include <queue>
int dist[NM];
queue<int> Q;
void pro() {
	Q.push(N);
	for (int i = 0; i <= 100000; i++) dist[i] = -1;
	dist[N] = 0;
	while (!Q.empty()){
		int x = Q.front();
		Q.pop();
		auto func = [](int x, int d){
			if (x < 0 || x > 100000 || dist[x] != -1) return;
			dist[x] = d;
			Q.push(x);
		};
		func(x - 1, dist[x] + 1);
		func(x + 1, dist[x] + 1);
		func(x * 2, dist[x] + 1);
	}
	cout << dist[K];
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}