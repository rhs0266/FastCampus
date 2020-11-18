#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff

using namespace std;

int n, ans_min = INF, ans_max = 0;

// 입력
void input() {
	cin >> n;
}

// x 라는 수 안에 홀수의 개수를 return하는 함수
int get_odd_cnt(int x) {
	int res = 0;
	while (x > 0) {
		int digit = x % 10;
		if (digit % 2 == 1) res++;
		x /= 10;
	}
	return res;
}

#include <string>
// x 라는 수에 도달했으며, 이때까지 등장한 홀수 자릿수가 total_odd_cnt 만큼 있을 때, 남은 경우를 모두 잘라보는 함수
void dfs(int x, int total_odd_cnt) {
    // 만약 한 자리 수면 더 이상 작업을 반복할 수 없으므로 정답을 갱신하고 종료한다.
	if (x <= 9) {
		ans_min = min(ans_min, total_odd_cnt);
		ans_max = max(ans_max, total_odd_cnt);
		return;
	}

    // 만약 두 자리 수면 2개로 나눠서 재귀호출한다.
	if (x <= 99) {
		int nx = (x / 10) + (x % 10);
		dfs(nx, get_odd_cnt(nx) + total_odd_cnt);
        return;
	}

    // 만약 세 자리 이상의 수면 가능한 3가지 자르는 방법을 모두 진행한다.
    string s = to_string(x);
    for (int i = 0; i <= s.length() - 3; i++) {
        for (int j = i + 1; j <= s.length() - 2; j++) {
            string x1 = s.substr(0, i + 1);  // s[0...i]
            string x2 = s.substr(i + 1, j - i);  // s[i+1...j]
            string x3 = s.substr(j + 1, s.length() - 1 - j);  // s[j+1...end]

            // 나눠진 세 수를 더해서 재귀호출
			int nx = stoi(x1) + stoi(x2) + stoi(x3);
            dfs(nx, get_odd_cnt(nx) + total_odd_cnt);
        }
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	input();
    
    // 제일 처음에는 n 이라는 수를 들고 있으며 여기에 속한 홀수 개수로 시작한다.
	dfs(n, get_odd_cnt(n));
	cout << ans_min << " " << ans_max << '\n';
	return 0;
}