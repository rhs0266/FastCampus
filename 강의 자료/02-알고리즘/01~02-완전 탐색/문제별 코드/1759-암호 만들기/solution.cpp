#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;

int N, M, selected[16];
char chars[16];
void input() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) cin >> chars[i];
}

bool isVowel(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

void rec_func(int k) {
	if (k == M + 1) {
		int vowel = 0, consonant = 0;
		for (int i = 1; i <= M; i++) {
			if (isVowel(chars[selected[i]])) vowel++;
			else consonant++;
		}
		if (vowel >= 1 && consonant >= 2) {
			for (int i = 1; i <= M; i++) cout << chars[selected[i]];
			cout << "\n";
		}
		return;
	}
	for (int cand = selected[k - 1] + 1; cand <= N; cand++) {
		selected[k] = cand;
		rec_func(k + 1);
		selected[k] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	sort(chars + 1, chars + 1 + N);
	rec_func(1);
	return 0;
}