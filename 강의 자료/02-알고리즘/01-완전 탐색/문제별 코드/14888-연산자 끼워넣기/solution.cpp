#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;

int N, nums[15], operators[5], ans_max, ans_min;
void input() {
	cin >> N;
	for (int i=1;i<=N;i++) cin >> nums[i];
	for (int i=1;i<=4;i++) cin >> operators[i];
	ans_max = -0x80000000;
	ans_min = 0x7fffffff;
}

// 피연산자 2개와 연산자가 주어졌을 때 계산해주는 함수
int calculator(int operand1, int op, int operand2){
	// value, order[i], num[i+1]
	if (op == 1) // +
		return operand1 + operand2;
	else if (op == 2) // -
		return operand1 - operand2;
	else if (op == 3) // *
		return operand1 * operand2;
	else // /
		return operand1 / operand2;
}

void rec_func(int k,int value) {
	if (k == N) {
		ans_max = max(ans_max, value);
		ans_min = min(ans_min, value);
		return;
	}
	for (int cand = 1; cand <= 4; cand++) {
		if (operators[cand] >= 1){
			operators[cand]--;
			rec_func(k + 1, calculator(value, cand, nums[k + 1]));
			operators[cand]++;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	rec_func(1, nums[1]);
	cout << ans_max << '\n' << ans_min;
	return 0;
}