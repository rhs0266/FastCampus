#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

int N, cnt[30], kind;
string A;

void input() {
	cin >> N;
	cin >> A;
}
void add(char x) {  // x 라는 알파벳 추가
	cnt[x - 'a']++;
	if (cnt[x - 'a'] == 1)  // 새롭게 나타난 알파벳이라는 뜻
		kind++;
}

void erase(char x) {  // x 라는 알파벳 제거
	cnt[x - 'a']--;
	if (cnt[x - 'a'] == 0)  // 인식해야 하는 알파벳에서 빠지는 순간
		kind--;
}

void pro() {
	int len = A.length(), ans = 0;
	for (int R = 0, L = 0; R < len; R++) {
		// R 번째 문자를 오른쪽에 추가
		add(A[R]);

		// 불가능하면, 가능할 때까지 L을 이동
		while (kind > N) {
			erase(A[L++]);
		}

		// 정답 갱신
		ans = max(ans, R - L + 1);
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}